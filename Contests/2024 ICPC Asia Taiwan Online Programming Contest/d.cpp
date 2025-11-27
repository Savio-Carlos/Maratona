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

const int MOD = 1e9+7;

int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};
int n, m, d0, d1, d2;

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}

int modiv(int a, int b){
    return (a%MOD * fastExpo(b, MOD-2)) % MOD;
}

bool valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

signed main(){
    winton;
    cin >> n >> m >> d2 >> d1 >> d0;

    vector<vector<char>> grid(n, vector<char>(m));

    int tot = 0, ans = 0;

    for (auto &i : grid) for (auto &j : i) {cin >> j; if (j == '?') tot++;};
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int a2 = 0;
            int a1 = 0;
            int a0 = 0;
            
            for (auto x : dx){
                for (auto y : dy){
                    if (valid(i+x, j+y)){
                        if (grid[i+x][j+y] == '?'){
                            if (abs(x) + abs(y) == 2) a0++;
                            else if (abs(x) + abs(y) == 1) a1++;
                            else a0++;
                        }
                    }
                }
            }
            int around = fastExpo(2LL, a0 + a1 + a2);
            debug(i, j, a2, a1, a0, around);

            ans = ans + ((around - modiv(around, fastExpo(2LL,a2))) * d2);
            around = around - modiv(around, fastExpo(2LL,a2));
            ans = ans + ((around - modiv(around, fastExpo(2LL,a1))) * d1);
            around = around - modiv(around, fastExpo(2LL,a1));
            ans = ans + ((around - modiv(around, fastExpo(2LL,a0))) * d0);
            around = around - modiv(around, fastExpo(2LL,a0));
            
            debug(ans);
        }
    }
}