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
bool check(int a, int b, int c) {
    return (a != b && b != c && a != c);
}
bool checkTriangle(int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (check(a[i], a[j], a[k]) && checkTriangle(a[i], a[j], a[k])) {
                    ans++;
                }
            }
        }
    }
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