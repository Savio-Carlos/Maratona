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
const int MAX = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

template<int p> struct mod_int {
	int expo(int b, int e) {
		int ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	int inv(int b) { return expo(b, p-2); }
 
	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(int v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * (a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(int e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }
 
	friend istream& operator >>(istream& in, m& a) {
		int val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, int e) { return a ^= e; }
};
 
typedef mod_int<MOD> mint;

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,mint>>> segs(m+1);
    mint notchance = 1;//probabilidade de nenhum segmento ser escolhido
    for(int i = 0; i < n; i++){
        int l, r;
        mint p, q;
        cin >> l >> r >> p >> q;

        segs[r].push_back({l,(p/(q-p))});
        /*  probabilidade total de todo mundo = produto de p/q * produto de 1- p/q
        
            pegar a razão entre a probabilidade de um segmento existir e a probabilidade de ele não existir.

            isso seria escolher / nao escolher = pi/qi / (qi-pi)/qi = pi/(qi-pi)
            dp ta guardando a chance dos elementos serem mutualmente exclusivos, por isso guardamos a razao entre escolher x nao escolher
        */
       notchance *= ((q-p)/q);//probabilidade desse segmento nao ser escolhido (1 - probabilidade dele ser escolhido)
    }

    vector<mint> dp(m+1);
    dp[0] = 1;

    for (int r = 1; r <= m; r++){
        for (auto [l, pr]: segs[r]){
            dp[r] += dp[l-1] * pr;
            /*
            quando pegamos esse segmento para cobrir l-r e multiplicamos ele por pr, qual a contribuicao disso para a dp final?
            evita ter que subtrair probabilidades de sobreposição.
            Ao usar p/(q−p), a DP implicitamente lida com o fato de que um segmento "escolhido" para cobrir uma faixa o faz exclusivamente
            */
        }
    }
    cout << (notchance * dp[m]) << endl;
}