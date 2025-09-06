#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

int mod = 1e9 + 7;
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

int tcs(long long n) {
    int ans =  0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

void solve()
{
    long long n;
    int s;
    cin >> n >> s;
    if (tcs(n) <= s) {
        cout << 0 << "\n";
        return;
    } else {
        for (int i = 1; i <= 19; i++) {
            long long ten = 1;
            for (int j = 1; j < i; j++) {
                ten *= 10;
            }
            long long temp = (n / ten + 1) * ten;
            if (tcs(temp) <= s) {
                cout << temp - n << "\n";
                return;
            }
        }
    }
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