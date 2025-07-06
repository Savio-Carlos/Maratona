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

signed main() {
    int a, b;
    cin >> a >> b;
    int n = a%MOD;
    int m = b%MOD;
    int linhas = ((n*(n+1))/2) % MOD; 
    int colunas = ((m*(m+1))/2) % MOD; 
    int retangulos = (linhas*colunas) % MOD;
    int rects = mod_mul( mod_mul(n, (n+1)%MOD),mod_mul(m, (m+1)%MOD)) % MOD;
    //debug(rects);
    //debug(retangulos);

    int mn = min(n, m) % MOD;
    int t1 = (mn+1) * n * m;
    int t2 = (mn * (mn+1) * (2*mn+1)) / 6;
    int t3 = n * (mn * (mn+1)) / 2;
    int t4 = m * (mn * (mn+1)) / 2;
    int quadrados = t1 + t2 - t3 - t4;
    //debug(quadrados);
    cout << (retangulos-quadrados) % MOD << endl;
}