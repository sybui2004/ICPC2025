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

/*
dp[i] là số cách để tạo được xâu s[0:i-1].
duyệt từ i = 1 đến n, và kiểm tra các đoạn s[j..i-1] với độ dài tối đa bằng độ dài từ dài nhất trong từ điển.
*/
void solve()
{
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    unordered_set<string> dict;
    int maxl = 0;

    for (int i = 0; i < k; i++) {
        string x;
        cin >> x;
        dict.insert(x);
        maxl = max(maxl, (int)x.size());
    }
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1; 

    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= maxl && l <= i; l++) {
            string sub = s.substr(i - l, l);
            if (dict.count(sub)) {
                dp[i] = (dp[i] + dp[i - l]) % mod;
            }
        }
    }

    cout << dp[n];
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