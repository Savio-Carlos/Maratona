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
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

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

const int MOD = 998244353;

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
		v = v * (a.v) % p;//tirar o int quando for usar define int long long
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

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(6));
    vector<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> a[i][j];
            s.push_back(a[i][j]);
        }
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int k = s.size();
    vector<vector<int>> upd(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            int id = lower_bound(s.begin(), s.end(), a[i][j]) - s.begin();
            upd[id].push_back(i);
        }
    }   
    for (int i = 0; i < k; i++){
        debug(i, upd[i]);
    }
        mint ans = 0;
    vector<int> b(n);
    mint prod = 1;
    int zero_cnt = n;
    for (int i = 0; i < k - 1; i++) {
        for (int j: upd[i]) {
            if (!b[j]) {
                --zero_cnt;
            } else {
                prod /= b[j];
            }
            ++b[j];
            prod *= b[j];
        }
        ans -= (zero_cnt ? 0 : prod) * (s[i + 1] - s[i]);
        debug(ans);
    }
    ans /= mint(6)^(n);
    ans += s[k - 1];
    cout << ans << endl;
}
