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

// dp[a][b][c] = 1 + a/S.dp[a+1][b][c] + b/S.dp[a][b+1][c] + c/S.dp[a][b][c+1]
double dp[101][101][101];
bool seen[101][101][101];
double cal(int a, int b, int c) {
    if (a >= 100 || b >= 100 || c >= 100) return 0.0;
    if (seen[a][b][c]) return dp[a][b][c];
    seen[a][b][c] = true;
    double sum = a + b + c;
    double res = sum;
    res += a * cal(a + 1, b, c);
    res += b * cal(a, b + 1, c);
    res += c * cal(a, b, c + 1);
    res /= sum;
    dp[a][b][c] = res;
    return res;
}
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << setprecision(6) << fixed << cal(a, b, c) << "\n";
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