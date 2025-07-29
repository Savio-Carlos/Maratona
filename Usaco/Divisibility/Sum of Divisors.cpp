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
const int MAX = 1e6+7;
const int MOD = 1e9+7;
/*
D(12) = 1 2 3 4 6 
D(11) = 11 
D(10) = 2 5 
D(9) = 3 9 
D(8) = 2 4 
D(7) = 7
D(6) = 2 3 6 
D(5) = 5 
D(4) = 2 4 
D(3) = 3
D(2) = 2
D(1) = 1

12*1
6*2
4*3

3*4 
2*5
2*6

1*7
1*8
1*9
1*10
1*11
1*12

quantidade de vezes que o numero aparece como divisor
1  2 3 4 5 6 7 8 9 10 11 12
12 6 4 3 2 2 1 1 1 1  1  1

n vai aparecer 1 vez 
o 1 vai aparecer n/2 vezes

para o 25
1  2  3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
25 12 8 6 5 4 3 3 2 2  2  2  1  1  1  1  1  1  1  1


como calcular essa sequencia?
do n/1 ate o n/2 todos são 1 (vai dar 13)
do n/2 ate o n/3 todos são 2 (do 12 ao 8) = 4 correto
do n/3 ate o n/4 todos são 3 (do 8 ao 6) deu 2 correto
do n/4 ate o n/5 todos são 4 (do 6 ao 5) deu 1 correto
e aqui eu fui ate a raiz
ai o restante eu calculo indo do 1 ate a raiz e fazendo (n/i)*i
*/
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
 
typedef mod_int<(int)MOD> mint;

mint pa(mint n, mint a1){
    return ((n-a1+1)*(a1+n))/2;
}

signed main(){
    winton;
    int n;
    cin >> n;
    mint ans = 0;
    for (int i = 1; i*i <= n; i++){
        ans += (n/i * i);
    }
    for (int i = 1; i*i+i <= n; i++){
        mint x = pa(n/i, n/(i+1)+1);
        ans += x * i;
    }
    cout << ans << endl;

}