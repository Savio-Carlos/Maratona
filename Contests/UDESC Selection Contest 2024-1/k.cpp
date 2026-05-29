#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    template<class A, class B> ostream& operator<<(ostream& o, const pair<A,B>& p) {
        return o << '(' << p.first << ", " << p.second << ')';
    }
    template<class T, class = enable_if_t<!is_same_v<T,string> && !is_same_v<T,string_view>>>
    auto operator<<(ostream& o, const T& v) -> decltype(v.begin(), o) {
        o << '{'; bool f = 1;
        for (auto& x : v) { o << (f ? "" : ", ") << x; f = 0; }
        return o << '}';
    }
    void out(string_view) { cerr << '\n'; }
    template<class H, class... T> void out(string_view s, H h, T... t) {
        auto c = s.find(',');
        cerr << s.substr(0, c) << " = " << h;
        if constexpr (sizeof...(t)) {
            cerr << " | ";
            out(s.substr(s.find_first_not_of(" ,", c)), t...);
        } 
        else cerr << '\n';
    }
}
using namespace dbg;

// #define DEBUG

#ifdef DEBUG
    #define winton (void)0
    #define debug(...) cerr << "[" << __LINE__ << "] ", out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

const int MOD = 998244353;

struct matrix : vector<vector<int>> {
    int n, m;

    matrix(int n_, int m_, bool ident = false) : vector<vector<int>>(n_, vector<int>(m_, 0)), n(n_), m(m_) {
        if (ident) {
            assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}

    matrix(const vector<vector<int>>& c) : vector<vector<int>>(c),
    n(c.size()), m(c[0].size()) {}

    matrix operator*(const matrix &a) const {
        assert(m == a.n);
        matrix res(n, a.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < a.m; j++){
                for (int k = 0; k < m; k++){
                    res[i][j] = (res[i][j] + ((*this)[i][k] * a[k][j]) %(MOD-1)) %(MOD-1);
                }
            }
        }
        return res;
    }

    matrix operator^(int e) const {
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

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}

signed main(){
    winton;
    int n;
    cin >> n;
    if (!n){
        cout << 1 << endl;
        return 0;
    }

    vector<vector<int>> bb = {{1,1},{1,0}};
    matrix b(bb);
    b = b ^(n-1);
    debug(b);
    int e = b[0][0]%(MOD-1);
    cout << fastExpo(2LL, e)%MOD << endl;
}