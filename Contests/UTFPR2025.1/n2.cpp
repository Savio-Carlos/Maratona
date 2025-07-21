#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 1e5+7;
const int INF = LLONG_MAX;
const int MOD = 998244353;

int mod_mul(int x, int y) {
    return (x % MOD) * (y % MOD) % MOD;
}

int mod_pow(int x, int e = MOD-2) {
    int r = 1;
    while (e) {
        if (e & 1) r = (r * x) % MOD;
        x = (x * x) % MOD;
        e >>= 1;
    }
    return r;
}

signed main() {
    winton;
    int a, b;
    cin >> a >> b;

    int n = a % MOD;
    int m = b % MOD;
    const int inv2 = mod_pow(2);
    const int inv6 = mod_pow(6);

    int linhas   = mod_mul(mod_mul(n, (n+1) % MOD), inv2);
    int colunas  = mod_mul(mod_mul(m, (m+1) % MOD), inv2);
    int retangulos = mod_mul(linhas, colunas);
    int mn = min(n, m);
    int t1 = mod_mul(mn + 1, mod_mul(n, m));
    int t2 = mod_mul(mod_mul(mod_mul(mn, mn+1), (2*mn+1) % MOD), inv6);
    int t3 = mod_mul(n, mod_mul(mod_mul(mn, mn+1), inv2));
    int t4 = mod_mul(m, mod_mul(mod_mul(mn, mn+1), inv2));
    int quadrados = ((t1 + t2) % MOD - (t3 + t4) % MOD + MOD) % MOD;
    int resposta = (retangulos - quadrados + MOD) % MOD;
    cout << resposta << endl;
}
