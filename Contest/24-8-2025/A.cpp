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

struct Node {
    int nxt[2];
    int cnt;
    Node() { nxt[0] = nxt[1] = -1; cnt = 0; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    const int BITS = 19;
    const int U = 1 << BITS;

    vector<char> present(U, 0);
    for (int x : a) present[x] = 1;

    vector<Node> tr;
    tr.reserve((int)present.size() * 2);
    tr.emplace_back(); 
    auto insert = [&](int val) {
        int u = 0;
        for (int i = BITS - 1; i >= 0; --i) {
            int b = (val >> i) & 1;
            if (tr[u].nxt[b] == -1) {
                tr[u].nxt[b] = (int)tr.size();
                tr.emplace_back();
            }
            u = tr[u].nxt[b];
            tr[u].cnt++; 
        }
    };

    for (int v = 0; v < U; ++v)
        if (present[v]) insert(v);

    auto mex_after_xor = [&](int L) {
        int u = 0, res = 0;
        for (int i = BITS - 1; i >= 0; --i) {
            int b = (L >> i) & 1;
            int go = (tr[u].nxt[b] == -1) ? -1 : tr[u].nxt[b];
            int cap = 1 << i; 

            if (go != -1 && tr[go].cnt == cap) {
                res |= (1 << i);
                int alt = tr[u].nxt[b ^ 1];
                if (alt == -1) return res; 
                u = alt;
            } else {
                if (go == -1) return res; 
                u = go;
            }
        }
        return res; 
    };

    int lazy = 0;
    while (m--) {
        int x; cin >> x;
        lazy ^= x;
        cout << mex_after_xor(lazy) << '\n';
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