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

int countP(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

ll fibo[91];

void solve(int n, int k)
{
    vi primes;
    for (int i = 0; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    ll ans = 1;
    for (int p : primes) {
        ans *= 1ll*(countP(n, p) - countP(k, p) - countP(n-k, p) + 1);
    }
    cout << ans << "\n";
}

int main()
{
    fast;
    sieve();
    int t = 1;
    string line;

    while (getline(cin, line))
    {
        stringstream ss(line);
        int n, k;
        ss >> n >> k;
        solve(n, k);
    }
}