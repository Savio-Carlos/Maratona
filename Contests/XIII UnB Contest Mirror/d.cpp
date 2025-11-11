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
const int MOD = 10000;
const int HMOD = 1e9+7;

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> ha, hb;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i){
            ha.push_back(abs((a[i-1] - a[i]) + MOD) % MOD);
            debug(abs((a[i-1] - a[i]) + MOD) % MOD);
        }
    }
    
    for (int i = 0; i < m; i++){
        cin >> b[i];
        if (i){
            debug(abs((b[i-1] - b[i]) + MOD) % MOD);
            hb.push_back(abs((b[i-1] - b[i]) + MOD) % MOD);
        }
    }

    debug(ha, hb);

    int S = hb.size(), T = ha.size();
    
    vector<int> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) p_pow[i] = (p_pow[i-1] * P) % HMOD;
    
    vector<int> h(T + 1, 0); 
    for (int i = 0; i < T; i++) h[i+1] = (h[i] + (ha[i]) * p_pow[i]) % HMOD; //hash do texto(vetor a)
    
    int h_s = 0; 
    for (int i = 0; i < S; i++) h_s = (h_s + (hb[i]) * p_pow[i]) % HMOD; //hash da string s (vetor b)
    
    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        int cur_h = (h[i+S] + HMOD - h[i]) % HMOD;
        if (cur_h == h_s * p_pow[i] % HMOD) occurrences.push_back(i);
    }
    map<int,int> cnt;
    for(auto u : occurrences){
        int shift = ((b[0] - a[u] + MOD) % MOD);
        cnt[shift]++;
    }
    debug(occurrences);
    debug(cnt);
    if (!cnt.empty()){
        auto comp = [](const auto& a, const auto& b) {
            return a.second < b.second; 
        };
        auto [shift, qtd] = *max_element(cnt.begin(), cnt.end(), comp);
        cout << shift << " " << qtd << endl;
    }
    else cout << "0 0\n"; 
}