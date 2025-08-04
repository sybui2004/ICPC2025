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

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 0; i < n; i++) cin >> b[i];

    // dp[k][c] = soda tối thiểu còn lại trong các chai không được chọn khi chọn k chai có tổng dung tích c
    vector<unordered_map<int, int>> dp(n + 1);
    dp[0][0] = s; // Tất cả soda đều ở chai không được chọn

    for (int i = 0; i < n; i++) {
        // Chọn chai i
        for (int k = min(i + 1, n); k >= 1; k--) {
            for (unordered_map<int, int>::iterator it = dp[k - 1].begin(); it != dp[k - 1].end(); it++) {
                int c = it->X;
                int soda = it->Y;
                int cn = c + b[i];
                int sodan = soda - a[i];
                
                if (dp[k].count(cn)) {
                    dp[k][cn] = min(dp[k][cn], sodan);
                } else {
                    dp[k][cn] = sodan;
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        int ans = INT_MAX;
        for (unordered_map<int, int>::iterator it = dp[k].begin(); it != dp[k].end(); it++) {
            int c = it->X;
            int soda = it->Y;
            if (c >= s) ans = min(ans, soda);
        }
        if (ans != INT_MAX) {
            cout << k << " " << ans;
            return;
        }
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