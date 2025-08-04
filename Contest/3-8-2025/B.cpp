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

void solve() {
    int n, x;
    cin >> n;
    vi le, chan;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i % 2 == 0) chan.push_back(x);
        else le.push_back(x);
    }
    if (n % 2) {
        for (int i = chan.size() - 1; i >= 0; i--) cout << chan[i] << " ";
        for (int i = 0; i < le.size(); i++) cout << le[i] << " ";
    } else {
        for (int i = le.size() - 1; i >= 0; i--) cout << le[i] << " ";
        for (int i = 0; i < chan.size(); i++) cout << chan[i] << " ";
    }
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