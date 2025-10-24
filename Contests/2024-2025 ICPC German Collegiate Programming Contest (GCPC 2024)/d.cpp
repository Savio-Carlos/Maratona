#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

/*
para achar o nivel de brilho num cara x qualquer
bx = somatorio p^(x - yi) * bi -> para todas as lanternas colocadas

onde bx e o brilho na posicao x e bi o brilho na posicao i
x e a posicao x e yi e a posicao y que estamos analisando

*/

const int MAX = 1e5+7;
const int MOD = 1e9+7;
const int DEN = 1e6;

int fastexpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}

int modiv (int a, int b){
    return ((a % MOD) * (fastexpo(b, MOD-2) % MOD)) % MOD;
}

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}

    void update(int i, int x) { 
        x %= MOD; // Garante que x esteja no range
        if (x < 0) x += MOD; // Trata x negativo
        for (i++; i <= n; i += i & -i) {
            bit[i] = (bit[i] + x) % MOD; // Adiciona com MOD
        }
    }
    int pref(int i) {
        int ret = 0;
        for (i++; i; i -= i & -i) {
            ret = (ret + bit[i]) % MOD; // Soma com MOD
        }
        return ret;
    }
    int query(int l, int r) {
        // Subtrai com MOD
        return (pref(r) - pref(l - 1) + MOD) % MOD; 
    }
};

signed main(){
    fastio;
    int n, q;
    string ps;
    cin >> n >> q >> ps;
    Bit bitl(n);
    Bit bitr(n);
    
    int p_num = 0;
    int p_den = 1;
    bool after_dot = false;
    for (char c : ps) {
        if (c == '.') {
            after_dot = true;
            continue;
        }
        if (after_dot) {
            p_num = p_num * 10 + (c - '0');
            p_den = p_den * 10;
        }
    }

    int p_frac = modiv(p_num, p_den);
    int r = (1 - p_frac + MOD) % MOD;

    while(q--){
        char t;
        cin >> t;
        if (t == '?'){
            int x;
            cin >> x;
            x--;
            int left = bitl.query(0, x);
            int right = bitr.query(x+1, n-1);
            int ansl = (fastexpo(r, x) * left) % MOD;  
            int ansr = modiv(right, fastexpo(r, x));
            cout << (ansl + ansr) % MOD << endl;  
        }
        else {
            int b, x;
            cin >> b >> x;
            x--;
            int vall = modiv(b, fastexpo(r, x)) % MOD; 
            int valr = (b * fastexpo(r, x)) % MOD;
            if (t == '+'){
                bitl.update(x, vall);
                bitr.update(x, valr); 
            }
            else {
                bitl.update(x, MOD-vall);
                bitr.update(x, MOD-valr); 
            }
        }
    }
}