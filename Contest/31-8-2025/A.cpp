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

int convert(char ch){
    if (ch == 'A') return 0;
    if (ch == 'B') return 1;
    return 2;
}


void solve() {
    string s;
    cin >> s;
    vector<deque<int>> deq(8);
    int ans = 0;
    for (char ch : s) {
        int b = convert(ch);
        int pre = -1, idx = -1;
        for (int mask = 6; mask >= 0; mask--) {
            if ((mask & (1<<b)) != 0) continue;
            if (!deq[mask].empty()) {
                pre = mask;
                idx = deq[mask].back();
                deq[mask].pop_back();
                break;
            }
        }
        if (idx == -1) {
            idx = ++ans;
            pre = 0;
        }
        int newMask = pre | (1<<b);
        if (newMask == 7) deq[0].push_back(idx);
        else deq[newMask].push_back(idx);
    }
    cout << ans;
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