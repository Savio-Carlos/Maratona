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

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MOD = 1e9+7;
const int MAX = 1e5+7;

int fat[MAX], invfat[MAX];

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}
int modinv(int n) {
    return fastExpo(n, MOD - 2);
}
int modiv (int a, int b){
    return (a * modinv(b) % MOD) % MOD;
}
void build(){
    fat[0] = 1;
    for (int i = 1; i < MAX; i++) fat[i] = (fat[i-1] * i) % MOD;
    invfat[MAX-1] = modinv(fat[MAX-1]);
    for (int i = MAX - 2; i >= 0; i--) invfat[i] = (invfat[i+1] * (i+1)) % MOD;
}
int comb(int a, int b){
    if (b > a || b < 0 || a < 0) return 0;
    return (((fat[a] * invfat[b]) % MOD) * invfat[a-b]) % MOD;
}

void solve(){
    int n, kk;
    cin >> n >> kk;
    vector<int> s(kk+1);
    
    for (int k = 1; k <= kk; k++){
        int t1 = modiv(1, k+1) % MOD;
        int t2 = (fastExpo(1 + n, k+1) - n - 1 + MOD) % MOD;
        int sum = 0;
        
        for (int i = 1; i < k; i++){
            sum = (sum + (comb(k+1, i) * s[i]) % MOD) % MOD;
        }
        
        t2 = ((t2 - sum) + MOD) % MOD;
        s[k] = (t1 * t2) % MOD;
    }
    debug(s);
    cout << s[kk] % MOD << endl;
}

signed main(){
    winton;
    build();
    int t;
    cin >> t;
    while(t--) solve();
}