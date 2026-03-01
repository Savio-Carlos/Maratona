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

int pa(int k){
    return (k * k+1) / 2;
}

signed main(){
    winton;
    int n, g;
    cin >> n >> g;
    vector<int> a(n + 1);
    vector<int> pfx(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pfx[i] = pfx[i-1] + a[i];
    }
    
    vector<int> dp_prev(n + 1, 0);
    vector<int> dp_cur(n + 1, 0);

    for (int k = 1; pa(k) <= n; k++) { //k tamanho do barco atual
        fill(all(dp_cur), 0);
        for (int i = pa(k); i <= n; i++) {//sempre comeco no primeiro indice que poderia colocar esse barco que e a pa(k)
            dp_cur[i] = max(dp_prev[i], dp_cur[i-1]);
            int profit = g - (pfx[i] - pfx[i-k]);
            dp_cur[i] = max(dp_cur[i], dp_prev[i - k] + profit);
        }
        debug(dp_prev, dp_cur);
        dp_prev = dp_cur;
    }
    cout << dp_cur[n] << endl;
}