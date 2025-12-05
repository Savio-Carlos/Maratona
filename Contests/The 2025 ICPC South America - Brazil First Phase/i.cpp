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

const int INF = 1e18;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> dist;
    vector<pair<int,int>> points(n);
    for (auto &[x, y] : points) cin >> x >> y;

    for (int i = 1; i < n; i++){
        auto [xi, yi] = points[i];
        auto [xf, yf] = points[i-1];
        dist.push_back(abs(xi-xf) + abs(yi-yf));
    }
    debug(dist);
    bool pos = true;
    int mnp = INF, mni = INF;
    vector<int> c(n-1);
    
    for (int i = 0; i < dist.size(); i++){
        if (i&1) mni = min(mni, dist[i]);
        else mnp = min(mnp, dist[i]);

        if (i > 1 && i < dist.size()-1){
            if (dist[i] > dist[i-1] && dist[i] > dist[i+1]) pos = false;
            debug(i);
        }
    }
    debug(mni, mnp);
    if (pos) cout << min(mni, mnp) - 1LL << endl;
    else cout << -1 << endl;
}