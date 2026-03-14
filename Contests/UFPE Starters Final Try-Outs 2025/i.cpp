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


const int MOD = 1e9+7;

// Matriz

#define MODULAR true
template<typename T> struct matrix : vector<vector<T>> {
    int n, m;
    
	void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << (*this)[i][j] << " ";
			cout << endl;
		}
	}
    
	matrix(int n_, int m_, bool ident = false) :
    vector<vector<T>>(n_, vector<T>(m_, 0)), n(n_), m(m_) {
        if (ident) {
            assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}
	matrix(const vector<vector<T>>& c) : vector<vector<T>>(c),
    n(c.size()), m(c[0].size()) {}
	matrix(const initializer_list<initializer_list<T>>& c) {
        vector<vector<T>> val;
		for (auto& i : c) val.push_back(i);
		*this = matrix(val);
	}
    
	matrix<T> operator*(matrix<T>& r) {
        assert(m == r.n);
		matrix<T> M(n, r.m);
		for (int i = 0; i < n; i++) for (int k = 0; k < m; k++)
        for (int j = 0; j < r.m; j++) {
            T add = (*this)[i][k] * r[k][j];
            #if MODULAR
            #warning Usar matrix<ll> e soh colocar valores em [0, MOD) na matriz!
            M[i][j] += add%MOD;
            if (M[i][j] >= MOD) M[i][j] -= MOD;
            #else
            M[i][j] += add;
            #endif
        }
		return M;
	}
	matrix<T> operator^(int e){
		matrix<T> M(n, n, true), at = *this;
		while (e) {
			if (e&1) M = M*at;
			e >>= 1;
			at = at*at;
		}
		return M;
	}
	void apply_transform(matrix M, int e){
        auto& v = *this;
		while (e) {
            if (e&1) v = M*v;
			e >>= 1;
			M = M*M;
		}
	}
};


signed main(){
    winton;
    int n, a, b;
    cin >> n >> a >> b;
    if (n <= 2){
        cout << (n == 1? a : b) << endl;
        return 0;
    }
    matrix m()

}