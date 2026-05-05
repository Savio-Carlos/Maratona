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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


/*
se eu tiver um numero par de folhas na minha subarvore(v), sempre e otimo conectar elas agora
se tiver um impar, ela vai passar pela edge Paiv - v, entao conta +1
mas se tiver um nuymero impar de folhas entao uma nao vai ser usada
qual e a melhor pra remover?


*/

const int MAX = 2e5+7;

int ans = 0;
vector<int> graph[MAX];
int fol[MAX];

void dfs(int v, int p){
    if (graph[v].size() == 1 && p != 0) fol[v] = 1;

    for (auto u : graph[v]){
        if (u == p) continue;
        dfs(u,v);
    }

    for (auto u : graph[v]){
        if (u == p) continue;
        fol[v] = (fol[v] + fol[u]) % 2;
    }
    if (fol[v] && v != 1) ans++;
    debug(v, fol[v]);

}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        fol[i] = 0; 
        graph[i].clear();
    } 
    
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ans = 0;
    dfs(1,0);
    cout << ans << endl;
}

signed main(){
    winton;
    int t = 1;
    cin >> t;
    while(t--) solve();
}

