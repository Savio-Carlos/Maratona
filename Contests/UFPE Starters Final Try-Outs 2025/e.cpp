#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 2000;
const int MOD = 1E9+7;

int fastexpo(int base, int exp){
    int r = 1;
    while(exp){
        if(exp&1) r = r*base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return r%MOD;
}

int modinv(int n){
    return fastexpo(n, MOD-2);
}

int modiv(int a, int b){
    return a * modinv(b) % MOD;
}


struct BIT {
	int n;
	vector<int> bit;
	BIT(int _n = 0) : n(_n), bit(n + 1) {}

	BIT(vector<int>& v) : n(v.size()), bit(n + 1,1) {
		for (int i = 1; i <= n; i++) {
			bit[i] = (bit[i] * v[i-1]) %MOD;
			int j = i + (i & -i);
			if (j <= n) bit[j] = (bit[j] * bit[i]) %MOD;
		}
	}
	// void update(int i, int x) { // soma x na posicao i
	// 	for (i++; i <= n; i += i & -i) bit[i] += x;
	// }

	int pref(int i) { // soma [0, i]
		int ret = 1;
		for (i++; i; i -= i & -i) ret = (ret * bit[i]) % MOD;
		return ret;
	}
	int query(int l, int r) {  // soma [l, r]
		return modiv(pref(r), pref(l - 1)) % MOD; 
	}
};

signed main(){
    winton;
    int n, q;
    cin >> n >> q;
    vector<int> p(n), pi(n);
    
    for(int i = 0; i < n; i++){
        cin >> p[i];
        pi[i] = modiv(100-p[i], 100);
        p[i] = modiv(p[i], 100);
    }
    BIT bit_inversa(pi);
    debug(pi);
    debug(bit_inversa.bit);

    while(q--){
        int t;
        cin >> t;
        if (t == 2){
            int x;
            cin >> x;
            int p0 = bit_inversa.query(x, n-1);
            debug(p0);
        }
        else {
            int p;
            cin >> p;
        }
    }
    
    
    
}

/*
uma bit pra calcular a probabilidade de nao parar em nenhum floor do x ate o n+1
outra bit pra calcular a probabilidade de parar exatamente em cada floor e somar essas probabilidades
precisa alterar o template da bit de soma pra multiplicacao

como lidar com o caso da probabilidade de um andar parar for alterada?
em qualquer momento, a probabilidade do elevador parar somente no andar i é 
probabilidade dele parar nesse andar * a probabilidade dele nao parar em nenhum outro
mas isso depende do tamanho do intervalo

P(i ser o unico que para) = Pp(i) * Somatorio Pnp(j) ate i-1 * Somatorio Pnp(j) ate n
calculo a chance de cada cara ser o unico pro intervalo inteiro
na hora de fazer update eu preciso tirar a probabilidade antiga fazendo modiv no intervalo inteiro e depois multiplicando a nova probabilidadae
na hora de fazer a query eu preciso isolar e pegar so o produtorio a partir de x
entao eu faco modiv de todo o prefixo ate x na resposta
mas tem muita coisa se repetindo ai



*/