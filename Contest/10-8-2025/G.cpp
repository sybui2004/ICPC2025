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

vi a;
vector<vi> seg;

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = vector<int>(1, a[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2 + 1, mid + 1, r);

    seg[id].resize(seg[id*2].size() + seg[id*2+1].size());
    merge(seg[id*2].begin(), seg[id*2].end(),
          seg[id*2+1].begin(), seg[id*2+1].end(),
          seg[id].begin());
}

void update(int id, int l, int r, int pos, int oldVal, int newVal) {
    auto &v = seg[id];
    auto it = lower_bound(v.begin(), v.end(), oldVal);
    v.erase(it);
    
    auto p = lower_bound(v.begin(), v.end(), newVal);
    v.insert(p, newVal);

    if (l == r) return;
    int mid = (l + r) / 2;
    if (pos <= mid) update(id*2, l, mid, pos, oldVal, newVal);
    else update(id*2+1, mid + 1, r, pos, oldVal, newVal);
}

int query(int id, int l, int r, int u, int v, int X) {
    if (v < l || r < u) return -1; 
    if (u <= l && r <= v) {
        auto &vec = seg[id];
        auto it = upper_bound(vec.begin(), vec.end(), X);
        if (it == vec.end()) return -1;
        return *it;
    }
    int mid = (l + r) /2;
    int leftAns = query(id*2, l, mid, u, v, X);
    int rightAns = query(id*2 + 1, mid + 1, r, u, v, X);
    if (leftAns == -1) return rightAns;
    if (rightAns == -1) return leftAns;
    return min(leftAns, rightAns);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(n);
    seg.resize(4*n);
    for(int &i: a) cin >> i;
    build(1, 0, n-1);

    while (m--) {
        int type; cin >> type;
        if (type == 1) {
            int u, val; cin >> u >> val;
            u--;
            update(1, 0, n-1, u, a[u], val);
            a[u] = val;
        } else {
            int u, v, x; cin >> u >> v >> x;
            u--;
            v--;
            cout << query(1, 0, n-1, u, v, x) << "\n";
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