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
const int MAXN = 1e7 + 5;
int isPrime[MAXN];

// ll f[1005][1005];

// void Tohop()
// {
//     for(int i = 1; i <= 1000; i++) f[0][i] = 0;
//     for(int i = 1; i <= 1000; i++)
//     {
//         f[1][i] = i;
//         f[i][i] = 1;
//     }
//     for(int i = 2; i <= 1000; i++)
//     {
//         for(int j = 2; j <= i; j++) f[j][i] = (f[j-1][i-1]%mod + f[j][i-1]%mod)%mod;
//     }
// }

void sieve()
{
    for (int i = 2; i <= MAXN; i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    sort(all(a));

    vl prefix(n+1);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + a[i];

    ll ans = 0;
    for (int i = 1; i < n; i++) ans += a[i] * (i) - prefix[i-1];

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


