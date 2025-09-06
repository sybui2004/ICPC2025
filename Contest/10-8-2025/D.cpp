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

// dist(A, B) = |xA – xB| + |yA – yB| = max{|(xA + yA) - (xB + yB)|, |(xA - yA) - (xB - yB)|} = max(|uA - uB|, |vA - vB|)
// Xóa 1 trong các điểm có u = max(u) hoặc u = min(u) hoặc min(v) max(v)

struct Point {
    ll x, y, u, v;
};

int n;

ll cal(vector<Point> p, int pos) {
    ll umax = LLONG_MIN, umin = LLONG_MAX, vmax = LLONG_MIN, vmin = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        if (i == pos) continue;
        umax = max(umax, p[i].u);
        umin = min(umin, p[i].u);
        vmax = max(vmax, p[i].v);
        vmin = min(vmin, p[i].v);
    }
    return max(umax - umin, vmax - vmin);
}

void solve()
{
    cin >> n;
    vector<Point> p(n);
    for (Point &i : p){
        cin >> i.x >> i.y;
        i.u = i.x + i.y;
        i.v = i.x - i.y;
    }

    ll umax = LLONG_MIN, umin = LLONG_MAX, vmax = LLONG_MIN, vmin = LLONG_MAX;
    for (Point &i : p) {
        umax = max(i.u, umax);
        umin = min(i.u, umin);
        vmax = max(i.v, vmax);
        vmin = min(i.v, vmin);
    }

    vi val;
    for (int i = 0; i < n; i++) {
        if (p[i].u == umax || p[i].u == umin || p[i].v == vmax || p[i].v == vmin) {
            val.push_back(i);
        }
    }
    
    ll ans = LLONG_MAX;

    for (int i : val)
        ans = min(ans, cal(p, i));

    cout << ans << "\n";

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