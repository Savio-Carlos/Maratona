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

void setIO(string name = "") {
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int dp[20][20][2][20]; // [index][cnt][tight][ldz]
int n;
string s;

int DIGITO;
int MODE;
int OTHER;

int pd(int index, int cnt, int tight, int ldz){
    if(index == n){
        int len = n - ldz;
        if (len == 0) return 0;
        if (MODE == 0) return (2*cnt >= len);
        else return (len % 2 == 0 && cnt == len / 2);
    } 
 
    if (dp[index][cnt][tight][ldz] != -1) return dp[index][cnt][tight][ldz];
 
    int ub = tight ? s[index] - '0' : 9;
    int ans = 0;

    for (int digit = 0; digit <= ub; digit++){
        int new_tight = tight && (digit == ub);
        bool is_leading_zero = (digit == 0 && ldz == index);
        int new_ldz = ldz + is_leading_zero;

        if (MODE == 1 && !is_leading_zero && digit != DIGITO && digit != OTHER) continue;

        if (digit == DIGITO && !is_leading_zero) ans += pd(index + 1, cnt+1, new_tight, new_ldz);
        else ans += pd(index + 1, cnt, new_tight, new_ldz);
    }
    return dp[index][cnt][tight][ldz] = ans; 
}

int count(int x){
    s = to_string(x);
    n = s.size();

    int ans = 0;
    MODE = 0;
    for (DIGITO = 0; DIGITO <= 9; DIGITO++){
        memset(dp,-1, sizeof(dp));
        ans += pd(0,0,1,0);
    }

    int dup = 0;
    MODE = 1;
    for (DIGITO = 0; DIGITO <= 9; DIGITO++){
        for (OTHER = DIGITO + 1; OTHER <= 9; OTHER++){
            memset(dp,-1, sizeof(dp));
            dup += pd(0,0,1,0);
        }
    }
    
    debug(ans, dup);
    return ans - dup;
}

signed main(){
    winton;
    setIO("odometer");
    int l, r;
    cin >> l >> r;
    cout << count(r) - count(l-1) << endl;
}
