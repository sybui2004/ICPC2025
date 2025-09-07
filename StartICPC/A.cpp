#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);


struct Data
{
    long long s;
    int pos1, pos2;

    bool operator<(const Data &other) const {
        return s < other.s;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<Data> iJ, kP;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            iJ.push_back({a[i] + a[j], i, j});
        }
    }

    for (int p = 0; p < n; p++) {
        for (int k = 0; k < n; k++) {
            kP.push_back({3 * a[p] - a[k], k, p});
        }
    }

    sort(iJ.begin(), iJ.end());

    int ans = 0;
    for (auto &kp : kP) {
        auto it = lower_bound(iJ.begin(), iJ.end(), kp);
        if (it != iJ.end() && it->s == kp.s && kp.pos1 > it->pos2) {
            cout << it->pos1 << " " << it->pos2 << " " << kp.pos1 << " " << kp.s << "\n";
            ans++;
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


