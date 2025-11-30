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

signed main(){
    winton;
    int n;
    cin >> n;
    vector<vector<int>> dice(n, vector<int>(6,0));
    vector<vector<int>> cnt(n, vector<int>(7,0));//contagem de quantos de cada numero por dado
    vector<vector<int>> pfx(n, vector<int>(7,0));//probabilidade de todos os dados sairem <= j
    vector<int> tot(7,1);//probabilidade de todos os dados serem <= j

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 6; j++){
            cin >> dice[i][j];
            cnt[i][dice[i][j]]++;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 1; j <= 6; j++){
            pfx[i][j] = (pfx[i][j-1] + modiv(cnt[i][j], 6LL)) % MOD;
            tot[j] = tot[j] * pfx[i][j] % MOD;
        }
        debug(i, pfx[i]);
    }
    vector<int> e(7,0);
    for (int j = 1; j <= 6; j++){
        for (int i = 0; i < n; i++){
            int v = j;
            e[v] = (e[v] + modiv(tot[v], pfx[i][v])) % MOD;
            if (j != 1) e[v] = e[v] * modiv(cnt[i][v], 6LL) % MOD;
            
        }
    }   
    debug(tot);
    debug(e);

    int ans = 0;
    for (int i = 1; i <= 6; i++){
        ans = ans + (e[i] * i % MOD) % MOD;
    }


    cout << ans % MOD << endl;
}