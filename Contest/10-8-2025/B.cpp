#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
#define x first
#define y second
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define reset(a) memset(a, 0, sizeof(a))
#define mii map<int, int>
#define all(v) v.begin(), v.end()

ll mod = 1e9 + 7;
// const int MAxN = 1e7 + 5;
// int isPrime[MAxN];

// void sieve()
// {
//     for (int i = 2; i <= MAxN; i++)
//         isPrime[i] = 1;
//     isPrime[0] = isPrime[1] = 0;

//     for (int i = 2; i * i <= MAxN; i++)
//     {
//         if (isPrime[i])
//         {
//             for (int j = i * i; j <= MAxN; j += i)
//             {
//                 isPrime[j] = 0;
//             }
//         }
//     }
// }

// XOR(al, al+1,..ar) > XOR(ar+1, ar+2,...at) -> Thao tác: [(r − l + 1) - 1] + [(t − (r + 1) + 1) - 1] = t − l − 1

void solve()
{
    int n;
    cin >> n;
    vl a(n+1), pre(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1]^a[i];
    }

    if (n >= 130) {
        cout << 1;
        return;
    }

    int ans = INT_MAX;

    for (int l = 1;l <= n; l++) {
        for (int r = l; r <= n; r++) {
            ll left = pre[r] ^ pre[l-1];
            for (int t = r + 1; t <= n; t++) {
                ll right = pre[t] ^ pre[r];
                if (left > right) ans = min(ans, t - l - 1);
            }
        }
    }

    if (ans == INT_MAX) cout << -1;
    else cout << ans;
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