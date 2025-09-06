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

ll MOD = 998244353;
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

// Xét d có A[i]' = A[i]/d.
// Với mỗi d, tính số cách chọn (A[i]') sao cho:
// L[i]' = L[i]/d, R[i]' = R[i]/d
// sum(A[i]') <= M/d

// Với mỗi d, đếm số dãy (A'[i]) sao cho:
// A'[i] ∈ [L[i]', R[i]']
// sum A'[i] ≤ M' = M/d

// dp[s] = số cách chọn sao cho tổng là s.
// Đếm số cách với GCD chia hết cho d (gọi là F(d)).
// Số cách với GCD bằng 1 là: Tổng d từ 1 đến maxD (phi(d) x F(d)) với phi(d) là hàm Mobius.

void sieve_mobius(int maxD, vector<int> &mo) {
    mo.assign(maxD + 1, 1);
    vector<int> primes;
    vector<bool> isPrime(maxD + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= maxD; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            mo[i] = -1;
        }
        for (int p : primes) {
            if (i * p > maxD) break;
            isPrime[i * p] = false;
            if (i % p == 0) {
                mo[i * p] = 0;
                break;
            } else {
                mo[i * p] = -mo[i];
            }
        }
    }
}

// Đếm số sách để A[i] trong [l[i], r[i]], tổng <= M

ll count(const vector<pair<int, int>> &a, int sum) {
    int n = a.size();
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        vector<int> ndp(sum + 1, 0);
        // pre[s] = (dp[0] + dp[1] + ... + dp[s-1]) mod MOD
        vector<int> pre(sum + 2, 0);

        for (int s = 0; s <= sum; s++) {
            pre[s + 1] = (pre[s] + dp[s]) % MOD;
        }

        for (int s = 0; s <= sum; s++) {
            // dp: [s - r[i], s - l[i]]
            int left = s - a[i].second;
            if (left < 0) left = 0;
            int right = s - a[i].first;
            if (right < 0) right = -1;

            ll tmp = 0;
            if (right >= left) {
                tmp = pre[right + 1] - pre[left];
                if (tmp < 0) tmp += MOD;
            }
            ndp[s] = tmp % MOD;
            ndp[s] = tmp;
        }
        dp.swap(ndp);
    }

    int ans = 0;
    for (int i = 0; i <= sum; i++) {
        ans += dp[i];
        if (ans >= MOD) ans -= MOD;
    }
    return ans;
}



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    int maxR = 0;
    for (pair<int, int> &i: a) {
        cin >> i.first >> i.second;
        maxR = max(maxR, i.second);
    }
    vector<int> mo;
    sieve_mobius(maxR, mo);

    ll ans = 0;

    for (int d = 1; d <= maxR; d++) {
        vector<pair<int, int>> a_new(n);
        for (int i = 0; i < n; i++) {
            a_new[i].first = (a[i].first + d - 1) / d;
            a_new[i].second = a[i].second / d;        
        }

        int sum = m / d;

        ll tmp = count(a_new, sum);
        if (mo[d] == 1) {
            ans = (ans + tmp) % MOD;
        } else if (mo[d] == -1) {
            ans = (ans - tmp + MOD) % MOD;
        }
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