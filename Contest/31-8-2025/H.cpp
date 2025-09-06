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

int n;
bool check(vector<pair<ll, ll>> a, long long mid)
{
    long long miny = LLONG_MAX, maxy = LLONG_MIN;
    int p = 0;
    for (int r = 0; r < n; r++) {
        while (p < r && a[r].first - a[p].first >= mid) {
            miny = min(miny, a[p].second);
            maxy = max(maxy, a[p].second);
            p++;
        }
        if (miny != LLONG_MAX) {
            if (miny <= a[r].second - mid) return true;
            if (maxy >= a[r].second + mid) return true;
        }
    }
    return false;
}
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
void solve()
{
    cin >> n;
    vector<pair<ll, ll>> a(n);
    ll minx = LLONG_MAX, miny = LLONG_MAX, maxx = LLONG_MIN, maxy = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        minx = min(minx, a[i].first);
        miny = min(miny, a[i].second);
        maxx = max(maxx, a[i].first);
        maxy = max(maxy, a[i].second);
    }

    sort(a.begin(), a.end(), cmp);

    long long low = 0;
    long long high = min(maxx - minx, maxy - miny);
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (check(a, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << "\n";
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