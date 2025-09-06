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
#define anset(a) memset(a, 0, sizeof(a))
#define mii map<int, int>
#define all(v) v.begin(), v.end()

ll MOD = 998244353;
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
vi arr;
vector<bool> dd;

int ans, sum_edge;

int c[6][4] = {
    {0,1,2,3},
    {3,4,5,6},
    {6,7,8,0},
    {9,8,1,11},
    {9,7,5,10},
    {10,4,2,11}
};

void dq(int idx, int sum_edge) {
    if (idx == 12) {
        ans++;
        return;
    }

    for (int i = 0; i < 12; i++) {
        if (!dd[i]) {
            arr[idx] = a[i];
            dd[i] = true;

            bool ok = true;
            int new_sum_edge = sum_edge;
            // Cạnh chứa idx
            for (int e = 0; e < 6; e++) {
                bool ok1 = false;
                for (int k = 0; k < 4; k++) {
                    if (c[e][k] == idx) {
                        ok1 = true;
                        break;
                    }
                }
                if (ok1) {
                    int s = 0;
                    bool ok2 = true;
                    for (int j = 0; j < 4; j++) {
                        int pos = c[e][j];
                        if (arr[pos] == -1) {
                            ok2 = false;
                            break;
                        }
                        s += arr[pos];
                    }
                    if (ok2) {
                        // Đủ 4 điểm
                        if (new_sum_edge == -1) {
                            new_sum_edge = s;
                        } else if (s != new_sum_edge) {
                            ok = false;
                            break;
                        }
                    }
                }
            }

            if (ok) dq(idx + 1, new_sum_edge);

            arr[idx] = -1;
            dd[i] = false;
        }
    }
}

void solve()
{
    a.resize(12);
    for (int &i : a) cin >> i;

    sort(all(a));
    ans = 0;
    sum_edge = -1;

    arr.assign(12, -1);
    dd.assign(12, false);

    arr[0] = a[0];
    dd[0] = true;
    dq(1, -1);

    cout << ans << "\n";
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