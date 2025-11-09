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

const int INF = INT_MAX;
const int MAX = 503;

int n;
int dp[MAX][MAX*MAX];
pair<int,int> v[MAX];

int knapsack(int i, int w){
    if (w < 0 ) return -INF;
    if (i == n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    auto [peso, valor] = v[i];
    debug(i, w, dp[i][w], peso, valor);
    int pega = knapsack(i+1, w-peso) + valor; 
    debug(pega);
    int naopega = knapsack(i+1, w); 
    debug(naopega);

    return dp[i][w] = max(knapsack(i+1, w-peso) + valor, knapsack(i+1, w));
}

signed main(){
    winton;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    vector<int> h(n), b(n), w(n);
    int sum = 0, happi = 0;
    for (int i = 0; i < n; i++){
        cin >> w[i] >> h[i] >> b[i];
        sum += w[i];
        happi += b[i];
        v[i] = {w[i], h[i] - b[i]};
    }
    debug(sum, happi);
    int x = max(0LL, knapsack(0LL, sum/2LL));
    debug(dp[0][1]);
    debug(x);
    cout << happi + x << endl;
}