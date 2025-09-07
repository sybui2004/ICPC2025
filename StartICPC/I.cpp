#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define X first
#define Y second
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pil pair<int, ll>
#define plong longpair<ll, ll>
#define reset(a) memset(a, 0, sizeof(a))
#define mii map<int, int>
#define all(v) v.begin(), v.end()

long long mod = 1e9 + 7;
const int MAXN = 1e7 + 5;
// int isPrime[MAXN];

// long longf[1005][1005];

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

long long pow_a(int a, int b) {
    if (b == 0) return 1ll;
    long long cur = pow_a(a, b/2);
    if (b % 2 == 1) return cur * cur * a;
    else return cur * cur;
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

bool isPrime(int x) {
    if (x == 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }

    return true;
}

void solve()
{
    long long x;
    cin >> x;
    if (x == 1) {
        cout << 1;
        return;
    }
    int tmp = sqrt(x);
    
    for (int i = 1; i <= 100000; i++) {
        if (pow_a(i, 2) != x && pow_a(i, 3) != x) {
            if (pow_a(i, uoc(i)) == x) {
                cout << i;
                return;
            }
        }
        
    }

    for (int i = 1; i <= 1000000; i++) {
        if (pow_a(i, 3) == x && uoc(i) == 3) {
            cout << i;
            return;
        }
    }

    if (isPrime(tmp) && 1ll * tmp * tmp == x) {
        cout << tmp;
        return;
    }
    cout << -1;
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


