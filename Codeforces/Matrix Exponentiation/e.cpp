#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define int32 uint32_t
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

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


struct matrix : vector<vector<int32>> {
    int32 n, m;

    matrix(int32 n_, int32 m_, bool ident = false) : vector<vector<int32>>(n_, vector<int32>(m_, 0)), n(n_), m(m_) {
        if (ident) {
            assert(n == m);
			for (int32 i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}

    matrix(const vector<vector<int32>>& c) : vector<vector<int32>>(c),
    n(c.size()), m(c[0].size()) {}

    matrix operator*(const matrix &a){
        assert(m == a.n);
        matrix res(n, a.m);
        for (int32 i = 0; i < n; i++){
            for (int32 j = 0; j < m; j++){
                for (int32 k = 0; k < a.m; k++){
                    res[i][j] = (res[i][j] + (((*this)[i][k]) * (a[k][j]))) ;
                }
            }
        }
        return res;
    }

    matrix operator^(int32 e) const {
        matrix res(n,n,true);
        matrix base = *this;
        while (e) {
            if (e&1) res = res * base;
            base = base * base;
            e >>= 1;
        }
        return res;
    }
};

/*
se designarmos um vertice para cada posicao do tabuleiro de xadrez
seria v = i*j + j
cada posicao do tabuleiro se conecta com 
i+1 j+2
i+2 j+1
i-1 j+2
i-2 j+1
i-1 j-2
i-2 j-1
i+1 j-2
i+2 j-1

*/
int dx[] = {1,2,-1,-2,-1,-2,1,2};
int dy[] = {2,1,2,1,-2,-1,-2,-1};

signed main(){
    winton;
    int32 k;
    cin >> k;

    vector<vector<int32>> mat(65, vector<int32>(65));

    for (int32 i = 0; i < 8; i++){
        for (int32 j = 0; j < 8; j++){
            int32 v = i*8+j;
            mat[v][64] = 1;
            for (int32 d = 0; d < 8; d++){
                int nx = i+dx[d];
                int ny = j+dy[d];
                if (nx < 0 || nx > 7 || ny >= 8 || ny < 0) continue;
                int32 u = nx*8 + ny;
                debug(v,u);
                mat[v][u]++;
            }
        }
    }
    mat[64][64] = 1;

    matrix mt(mat);

    mt = (mt ^ k+1);
    cout << mt[0][64] << endl;
}