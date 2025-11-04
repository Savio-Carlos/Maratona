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

const int MAX = 2e5+7;

void solve(){   
    int n, m;
    cin >> n >> m;
    map<int,vector<int>> shafts;
    vector<int> score(n,0);//score atualmente no shaft n
    vector<tuple<int,int,int>> tunnels(m);
    for (int i = 0; i < m; i++){
        int l, r, v;
        cin >> l >> r >> v;
        l--;
        r--;
        tunnels[i] = {l,r,v};
        shafts[l].push_back(i);
        shafts[r].push_back(i);
    }
    for (int i = m-1; i >= 0; i--){
        //olhar o proximo tunel abaixo de mim e somar o score dele no meu do lado oposto
        auto [l,r,v] = tunnels[i];
        debug(i, l, r);

        int sl = score[l];
        int sr = score[r];

        score[l] = v + sr;
        score[r] = v + sl;
 
        debug(score);
        debug(i, l, score[l], r, score[r]);
    }
    debug(score);
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, score[i]);
        debug(i, shafts[i]);
    }
    cout << ans << endl;
    // debug(tunnels);
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}