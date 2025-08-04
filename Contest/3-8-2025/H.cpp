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

const int MAXN = 200005;
int par[MAXN];
int cnt[MAXN];

int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}

void unite(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b) {
        return;
    }
    if (cnt[a] < cnt[b]) swap(a, b);

    cnt[a] += cnt[b];
    par[b] = a;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        cnt[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (par[i] == i) ans = max(ans, cnt[i]);
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