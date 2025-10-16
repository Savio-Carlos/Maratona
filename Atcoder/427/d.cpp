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

const int MAX = 1e5+7;
const int MAXK = 22;

void solve(){
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    k = 2*k;

    vector<vector<int>> graph(n);
    
    for (int i = 0; i < m; i++){
        int a, b;       
        cin >> a >> b;
        graph[--a].push_back(--b);
    }

    vector<vector<int>> dp(k + 1, vector<int>(n));// ganhador[numero de movimentos][aresta] -> 0 ou 1 representando alice e bob

    for (int i = 0; i < n; i++){
        if (s[i] == 'A'){
            dp[k][i] = 0;
        }
        else dp[k][i] = 1;
    }

    for (int i = k-1; i >= 0; i--){
        int vez = i&1 ? 1 : 0;//bob = 1, alice = 0
        
        for (int v = 0; v < n; v++){
            if (!vez){ // alice joga nesse turno
                int r = 1; // assumindo que ela perde(bob ganha)
                for (auto u : graph[v]) {
                    r = min(r, dp[i + 1][u]);
                }
                dp[i][v] = r;
            }
            else{//bob joga nesse turno
                int r = 0; // alice ganha, bob perde
                for (auto u : graph[v]) {
                    r = max(r, dp[i + 1][u]);
                }
                dp[i][v] = r;
            }
        }
    }
    cout <<( (dp[0][0] == 0) ? "Alice" : "Bob" )<< endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}