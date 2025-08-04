/*Author: Bùi Thái Sỹ
 */
#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back
#define ll long long
#define FORU(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define X first
#define Y second
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define reset(a) memset(a, 0, sizeof(a))
#define mii map<int, int>
#define all(v) v.begin(), v.end()

ll mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int &i : a)
        cin >> i;

    vi freq(n + 1, 0);
    for (int x : a)
    {
        if (x <= n)
        {
            freq[x]++;
        }
    }

    vi miss(n + 2, 0);
    for (int i = 1; i <= n + 1; i++)
    {
        miss[i] = miss[i - 1] + (freq[i - 1] == 0);
    }

    vi prefix(n + 2, 0);
    for (int i = 0; i <= n; i++)
    {
        prefix[i + 1] = prefix[i] + freq[i];
    }

    vi diff(n + 2, 0);
    for (int k = 0; k <= n; k++)
    {

        if (miss[k] > 0)
            continue;

        int mi = freq[k];
        int cnt = 0;
        cnt += prefix[k] - k;
        cnt += prefix[n + 1] - prefix[k + 1];

        int ma = min(n, mi + cnt);
        diff[mi]++;
        diff[ma + 1]--;
    }

    vi ans(n + 1);
    int cur = 0;
    for (int i = 0; i <= n; i++)
    {
        cur += diff[i];
        ans[i] = cur;
    }

    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{

    fast;
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}