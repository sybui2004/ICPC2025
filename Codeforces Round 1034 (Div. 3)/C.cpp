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
    {
        cin >> i;
    }
    int mi = *min_element(all(a));
    int ma = *max_element(all(a));

    vi prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = min(prefix[i - 1], a[i]);
    }

    vector<int> suffix(n);
    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], a[i]);
    }

    for (int i = 0; i < n; i++)
    {

        if (a[i] == mi || a[i] == ma ||
            a[i] == prefix[i] || a[i] == suffix[i])
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
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