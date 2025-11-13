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

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int P = 31; 
const int MOD = 972663749;

struct hashing {
    vector<int> h, p_pow;
    string s;
    int n;
    
    hashing(string _s) : n(_s.size()), s(_s), h(_s.size()+1, 0), p_pow(_s.size(), 0) {} 

    void build(){
        p_pow[0] = 1; 

        for (int i = 1; i < n; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    }
    

    int get_hash(int l, int len){
        int r = l + len;
        return ((h[r] + MOD - h[l]) % MOD);
    }

    bool equal_substrings(int len) {
        if (!len) return true;

        int h1 = get_hash(0, len);
        int h2 = get_hash(n - len, len);

        int left  = (h1 * p_pow[n-len]) % MOD;
        int right = (h2) % MOD;
        return left == right;
    }
};

signed main(){
    winton;
    string s;
    cin >> s;

    hashing hash(s);
    hash.build();
    debug(hash.h);

    for (int i = 1; i < s.size(); i++){
        if (hash.equal_substrings(i)) cout << i << " ";
    }
}
