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

vector<int> step;
vector<set<int>> con;
void prepare() {
    step.assign(1001, 1e9);
    con.assign(1001, set<int>());

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            con[i].insert(int(i/j));
        }
    }
    // for (int i = 1; i <= 10; i++) {
    //     for (int j : con[i]) {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i <= 9; i++) {
        step[int(pow(2, i))] = i;
    }

    for (int i = 3; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            if (con[j].count(i-j)) {
                step[i] = min(step[i], step[j] + 1);
            }
            
        }
    }
    // for (int i = 1; i <= 10; i++) cout << step[i] << " ";

}
const int INF = 1e9;
void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> b(n), c(n);
    int C = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = step[b[i]];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int maxK = min(k, n * 12);
    vector<int> dp(maxK + 1, 0);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] > maxK) continue;
        for (int j = maxK; j >= b[i]; j--) {
            dp[j] = max(dp[j], dp[j-b[i]] + c[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int main()
{
    fast;
    prepare();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}