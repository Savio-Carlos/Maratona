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

int dp[65][2][2]; // [index][above][under]
string l, r;
int n;

int pd(int index, int above, int under) {
    if(index == n) return 0;

    if (dp[index][above][under] != -1) return dp[index][above][under];

    int ub = above ? r[index] - '0' : 1;
    int lb = under ? l[index] - '0' : 0;
    int ans = -1;

    for (int digit = lb; digit <= ub; digit++) {
        int new_above = above && (digit == ub);
        int new_under = under && (digit == lb);
        
        ans = max(ans, digit + pd(index + 1, new_above, new_under));
    }
    
    return dp[index][above][under] = ans; 
}

string to_bin(int x) {
    string s = "";
    while(x > 0) {
        s += to_string(x % 2);
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

void solve() {
    int ll, rr;
    cin >> ll >> rr;
    l = to_bin(ll);
    r = to_bin(rr);
    
    int pad = r.size() - l.size();
    if (pad > 0) l = string(pad, '0') + l;
    
    n = r.size();
    
    memset(dp, -1, sizeof(dp));
    cout << pd(0, 1, 1) << endl;
}

signed main() {
    winton;
    solve();
}