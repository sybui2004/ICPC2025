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

/*
prefix[r] - prefix[l-1] = (r-l+1) (mod k)
prefix[r] - r = prefix[l-1] - (l-1) (mod k)
r-l+1 < k
*/
void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n+1), prefix(n+1, 0);
    for (int i= 1; i <= n; i++) 
    {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }

    long long ans = 0;
    map<long long, deque<int>> pos;

    for (int i = 0; i <= n; i++) 
    {
        long long tmp = (prefix[i] - i) % k;
        
        while (!pos[tmp].empty() && i - pos[tmp].front() >= k) 
        {
            pos[tmp].pop_front();
        }
        
        ans += pos[tmp].size();
        pos[tmp].push_back(i);
    }


    cout << ans << "\n";
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