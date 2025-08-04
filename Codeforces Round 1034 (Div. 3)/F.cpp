/*Author: Bùi Thái Sỹ
 */
#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back
#define ll long long
#define FORU(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define X first
#define Y second
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define reset(a) memset(a, 0, sizeof(a))
#define mii map<int, int>
#define all(v) v.begin(), v.end()

ll mod = 1e9 + 7;

const int MAXN = 1e5;
vi d(1e5 + 1);

void sieve()
{
    for (int i = 0; i <= MAXN; i++)
    {
        d[i] = 1;
    }
    d[0] = d[1] = 0;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (d[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                d[j] = 0;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vi res(n + 1, 0);
    vector<bool> check(n + 1, false);
    vi primes;

    for (int i = 2; i <= n; i++)
        if (d[i])
            primes.push_back(i);

    reverse(all(primes));

    for (int p : primes)
    {
        vi tmp;
        for (int x = p; x <= n; x += p)
            if (!check[x])
            {
                tmp.push_back(x);
                check[x] = true;
            }

        int m = tmp.size();
        if (m > 1)
            for (int i = 0; i < m; i++)
                res[tmp[i]] = tmp[(i + 1) % m];
    }

    for (int i = 1; i <= n; i++)
        if (res[i] == 0)
            res[i] = i;

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";

    cout << "\n";
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    sieve();
    while (t--)
    {
        solve();
    }
}