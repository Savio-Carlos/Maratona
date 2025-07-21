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

int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int modInverse(int n) {
    return power(n, MOD - 2);
}

int mod_mul(int x, int y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

signed main() {
    winton;
    int a, b;
    cin >> a >> b;
    const int inv2 = modInverse(2);
    int term_a = mod_mul(a, a + 1);
    int total_linhas = mod_mul(term_a, inv2);
    int term_b = mod_mul(b, b + 1);
    int total_colunas = mod_mul(term_b, inv2);
    int total_retangulos = mod_mul(total_linhas, total_colunas);
    const int inv6 = modInverse(6);
    int n = min(a, b);
    int m = max(a, b);
    int n_mod = n % MOD;
    int n_plus_1 = (n + 1) % MOD;
    int term3 = (mod_mul(3, m) - (n_mod) + 1 + MOD) % MOD;
    int numerador = mod_mul(n_mod, mod_mul(n_plus_1, term3));
    int total_quadrados = mod_mul(numerador, inv6);
    int resposta = (total_retangulos - total_quadrados + MOD) % MOD;

    cout << resposta << endl;

    return 0;
}