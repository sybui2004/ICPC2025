#include "bits/stdc++.h"
using namespace std;

struct Dinic {
    struct Edge {
        int to, rev;
        int cap;
    };
    int n;
    vector<vector<Edge>> adj;
    vector<int> level, it;
    
    Dinic(int n) : n(n), adj(n), level(n), it(n) {}

    void addEdge(int u, int v, int cap) {
        adj[u].push_back({v, (int)adj[v].size(), cap});
        adj[v].push_back({u, (int)adj[u].size() - 1, 0});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : adj[u]) {
                if (level[e.to] < 0 && e.cap > 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int u, int t, int f) {
        if (u == t) return f;
        for (int &i = it[u]; i < (int)adj[u].size(); i++) {
            Edge &e = adj[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                int ret = dfs(e.to, t, min(f, e.cap));
                if (ret > 0) {
                    e.cap -= ret;
                    adj[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0, inf = 1e9;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (int f = dfs(s, t, inf)) {
                flow += f;
            }
        }
        return flow;
    }
};

struct Edge {
    int u, v, w;
};

int N, M;
vector<Edge> edges;

bool check(int k) {
    int S = 0;
    int edgeOffset = 1; 
    int vertexOffset = 1 + M;
    int T = vertexOffset + N;

    Dinic dinic(T + 1);

    for (int i = 0; i < M; i++) {
        dinic.addEdge(S, edgeOffset + i, edges[i].w);
        dinic.addEdge(edgeOffset + i, vertexOffset + edges[i].u - 1, edges[i].w);
        dinic.addEdge(edgeOffset + i, vertexOffset + edges[i].v - 1, edges[i].w);
    }
    for (int i = 0; i < N; i++) {
        dinic.addEdge(vertexOffset + i, T, k);
    }

    int flow = dinic.maxFlow(S, T);
    return flow == N * k;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    cin >> N >> M;
    edges.resize(M);
    int total = 0;
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        total += edges[i].w;
    }

    int low = 0, high = total / N, best = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    int keep = best * N;
    cout << total - keep << '\n';

    return 0;
}