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

// Kiểm tra 3 điểm thẳng hàng
bool check(pii a, pii b, pii c) {
    pii ab, bc;
    ab.X = b.X - a.X, ab.Y = b.Y - a.Y;
    bc.X = c.X - b.X, bc.Y = c.Y - b.Y;
    return 1ll * ab.X * bc.Y == 1ll * ab.Y * bc.X;
}
void solve()
{
    int n;
    cin >> n;
    vector<pii> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].X >> p[i].Y;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (!check(p[i], p[j], p[k])) result++;
            }
        }
    }

    cout << result;
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