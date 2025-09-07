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

int uoc(int a) {
    int ans = 1;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a != 1) {
            int cnt = 0;
            while (a % i == 0) {
                a /= i;
                cnt++;
            }

            ans *= (cnt+1);
            cnt = 0;
        }
    }
    if (a != 1) ans *= 2;
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    set<int> uoc;
    for (int &i: a) {
        cin >> i;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i != 1) {
                if (i % j== 0) uoc.insert(j);
                while (i % j == 0) {
                    i /= j;
                }
            }
        }
        if (i!=1) uoc.insert(i);
    }

    for (int i = 2; i <= m; i++)
        isPrime[i] = 1;
    isPrime[0] = 0, isPrime[1] = 1;

    for (int q: uoc) {
        for (int j = 1; j * q <= m; j++)
        {
            isPrime[j*q] = 0;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        if (isPrime[i]) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int i: ans) cout << i << " ";


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


