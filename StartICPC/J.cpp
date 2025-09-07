#include <bits/stdc++.h>
using namespace std;

vector<int> g[5005];
string s;
long long res;
vector<char> st;

void dfs(int u, int pu, int root) {
    char c = s[u-1];
    bool open = false;
    char closeChar = 0;

    if (c=='(' || c=='[' || c=='{') {
        st.push_back(c);
        open = true;
    } else {
        if (st.empty()) return; 
        char top = st.back();
        if ((c==')' && top=='(') ||
            (c==']' && top=='[') ||
            (c=='}' && top=='{')) {
            closeChar = top;
            st.pop_back();
        } else return; 
    }

    if (st.empty() && u != root) res++;

    for (int v : g[u]) {
        if (v == pu) continue;
        dfs(v, u, root);
    }

    // Backtrack
    if (open) st.pop_back();
    else st.push_back(closeChar);
}

void solve() {
    int n;
    cin >> n;
    cin >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    res = 0;
    st.reserve(n);

    for (int i = 1; i <= n; i++) {
        st.clear();
        dfs(i, 0, i);
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
