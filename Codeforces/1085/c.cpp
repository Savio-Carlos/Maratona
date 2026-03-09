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


void solve(){
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for(auto &u : a) cin >> u;

    vector<int> bestL(n+1, 0);//maximo de agua que um dreno pega entre as colunas 0...i
    vector<int> bestR(n+1, 0);//usar colunas i..n-1

    for(int i = 0; i < n; i++){
        int tot = 0, mx = 0;
        //colocar um dreno na coluna i

        for(int j = i; j >= 0; j--){//ver para a esquerda quanto de agua vai pegar
            mx = max(mx, a[j]);
            tot += max(0LL, h - mx);
        }
        mx = a[i];//terra ta no nivel do meu ralo
        bestL[i+1] = max(bestL[i+1], tot);

        for(int j = i+1; j < n; j++){//expandir pra direita pra ver quanto de agua vai pegar 
            mx = max(mx, a[j]);
            tot += max(0LL, h - mx);
            bestL[j+1] = max(bestL[j+1], tot);
        }
    }

    for(int i = n-1; i >= 0; i--){
        int tot = 0, mx = 0;
        for(int j = i; j < n; j++){
            mx = max(mx, a[j]);
            tot += max(0LL, h - mx);
        }
        mx = a[i];
        bestR[i] = max(bestR[i], tot);

        for(int j = i-1; j >= 0; j--){
            mx = max(mx, a[j]);
            tot += max(0LL, h - mx);
            bestR[j] = max(bestR[j], tot);
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) ans = max(ans, bestL[i] + bestR[i]);
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}