#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
int mod = 1e9 + 7;
using ll = long long;
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

struct Edge {
    int u, v;
    ll w;
};

vector<int> par;
vector<int> cnt;

int find(int x) {
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (cnt[a] < cnt[b]) swap(a, b);
    par[b] = a;
    if (cnt[a] == cnt[b]) cnt[a]++;
}

bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    ll s = 0;

    vector<Edge> edges(k);

    for (int i = 0; i < k; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        if (edges[i].w >= 0) s += edges[i].w;
    }
    
    par.resize(n+1);
    cnt.resize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    for (auto &e : edges) {
        if (e.w < 0) {
            unionSet(e.u, e.v);
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    ll res = 0;
    int used = 0;

    for (auto &e : edges) {
        if (e.w >= 0 && find(e.u) != find(e.v)) {
            unionSet(e.u, e.v);
            res += e.w;
            used++;
            if (used == n-1) break;
        }
    }

    cout << s - res;
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