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
// Tính số xâu bắt đầu bằng 'a'
// Nếu chọn 'a', còn lại A-1 ký tự 'a' và B ký tự 'b'
// Tổng số cách sắp xếp = C(A-1+B, A-1)
const int MAXN = 200005;

ll f[65][65];
void init()
{
    for(int i = 1; i <= 64; i++) f[0][i] = 1;
    for(int i = 1; i <= 64; i++)
    {
        f[1][i] = i;
        f[i][i] = 1;
    }
    for(int i = 2; i <= 64; i++)
    {
        for(int j = 2; j <= i; j++) f[j][i] = f[j-1][i-1] + f[j][i-1];
    }
}

void solve()
{
    int a, b;
    ll k;
    cin >> a >> b >> k;
    string ans = "";

    while (a > 0 && b > 0) {
        ll cntA = f[a - 1][a + b - 1];
        
        if (k <= cntA) {
            ans += 'a';
            a--;
        } else {
            ans += 'b';
            k -= cntA;
            b--;
        }
    }
    while (a--) ans += 'a';
    while (b--) ans += 'b';
    cout << ans;
}

int main()
{
    fast;
    init();
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}