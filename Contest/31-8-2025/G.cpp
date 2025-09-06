#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0);

using ll = long long;

ll gcdll(ll a, ll b) {
    return b ? gcdll(b, a % b) : a;
}

vector<ll> pf(ll n) {
    vector<ll> f;
    n = abs(n);
    if (n <= 1) return f;
    
    if (n % 2 == 0) {
        f.push_back(2);
        while (n % 2 == 0) n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            f.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

ll cal(const vector<ll>& a, ll x, ll p) {
    ll r = 0, pw = 1;
    for (ll c : a) {
        r = (r + ((c % p + p) % p) * pw) % p;
        pw = pw * x % p;
    }
    return r;
}

bool check_prime(const vector<ll>& a, ll p) {
    if (p > 1000) return false; 
    
    for (ll x = 0; x < p; x++) {
        if (cal(a, x, p) != 0) return false;
    }
    return true;
}

void solve() {
    int n; 
    cin >> n;
    
    if (n == 0) {
        ll c; 
        cin >> c;
        if (c != 0) {
            vector<ll> primes = pf(abs(c));
            for (auto p : primes) cout << p << "\n";
        }
        return;
    }
    
    vector<ll> a(n + 1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    
    reverse(a.begin(), a.end());
    
    bool all_zero = true;
    for (auto c : a) {
        if (c != 0) {
            all_zero = false;
            break;
        }
    }
    if (all_zero) return;
    
    ll g = abs(a[0]);
    for (int i = 1; i <= n; i++) {
        g = gcdll(g, abs(a[i]));
        if (g == 1) break;
    }
    
    set<ll> result;
    
    if (g > 1) {
        vector<ll> factors = pf(g);
        
        for (ll p : factors) {
            if (check_prime(a, p)) {
                result.insert(p);
            }
        }
    }
    
    vector<int> extra = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (auto p : extra) {
        if (g % p != 0) {
            if (check_prime(a, p)) {
                result.insert(p);
            }
        }
    }
    
    for (auto p : result) cout << p << "\n";
}

int main() {
    fast;
    solve();
}