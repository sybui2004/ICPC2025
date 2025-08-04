#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
#define X first
#define Y second
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define reset(a) memset(a, 0, sizeof(a))
#define mii map<int, int>
#define all(v) v.begin(), v.end()

ll mod = 1e9 + 7;
// const int MAXN = 1e7 + 5;
// int isPrime[MAXN];

// void sieve()
// {
//     for (int i = 2; i <= MAXN; i++)
//         isPrime[i] = 1;
//     isPrime[0] = isPrime[1] = 0;

//     for (int i = 2; i * i <= MAXN; i++)
//     {
//         if (isPrime[i])
//         {
//             for (int j = i * i; j <= MAXN; j += i)
//             {
//                 isPrime[j] = 0;
//             }
//         }
//     }
// }


/*
Tạo một mảng f để chứa các tập cùng màu.
Ban đầu khởi tạo f toàn -1. 
Duyệt i từ đầu tới cuối, tìm vị trí j đầu tiên trong f sao cho f[j] < a[i], sau đó thế f[j] = a[i]. 
Do f giảm dần nên ta có thể binary search được j. 
Đáp án là số lượng vị trí trong f khác -1.
*/

int lower_bound_vari(vi a, int n, int x) {
    int left = 0, right = n - 1;
    int res = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] < x) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return res;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int &i: a) cin >> i;
    vi f(n, -1);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound_vari(f, n, a[i]);
        f[pos] = a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] != -1) ans++;
    }
    cout << ans;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}