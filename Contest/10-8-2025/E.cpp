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

// P-positions
void solve()
{
    ll x, y;
    cin >> x >> y;
    if (llabs(x-y) <= 1) cout << "Bob";
    else cout << "Alice";
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