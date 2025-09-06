#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

int mod = 1e9 + 7;
using ll = long long;
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

ll fs(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    while (true) {
        if (a >= m) {
            ans += (ll)((n - 1) * n * (a / m) / 2);
            a %= m;
        }
        if (b >= m) {
            ans += (ll)(n * (b / m));
            b %= m;
        }
        ll y_max = a * n + b;
        if (y_max < m) break;
        ll n2 = y_max / m;
        ll m2 = a;
        ll a2 = m;
        ll b2 = y_max % m;
        n = n2; m = m2; a = a2; b = b2;
    }
    return ans;
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { 
        x = (a >= 0 ? 1 : -1); 
        y = 0; 
        return llabs(a); 
    }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll inv_mod(ll a, ll m) {
    ll x, y;
    ll g = extgcd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}


void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll N = (d - 1) / (c - b);
        if (N <= 0) { 
            cout << 0 << '\n'; 
            return; 
        }
        ll S = fs(N, d, c, a + c) - fs(N, d, b, a + b);

        ll  N0 = 0;
        ll  g = gcd(b, d);
        if (a % g == 0) {
            ll  m = d / g;            
            ll  Bb = b / g, Ab = a / g;
            ll  K0;
            if (m == 1) {
                K0 = 0;
            } else {
                ll  inv = inv_mod((Bb % m + m) % m, m);
                K0 = ((-Ab) % m + m) % m;
                K0 = K0 * inv % m;
            }
            ll  first = (K0 == 0 ? m : K0); 
            if (first <= N) N0 = 1 + (N - first) / m;
        }
        cout << (N - S - N0) << '\n';
}

int main()
{
    fast;
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}