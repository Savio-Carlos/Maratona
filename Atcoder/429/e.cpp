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

const int MAX = 2e5+7;
const int INF = LLONG_MAX;

int n, m, dist[MAX];
vector<vector<int>> graph;

void djikstra(string s){
    for (int i = 0; i < n; i++)dist[i]=INF;
    priority_queue<tuple<int,int,int>> pq;//dist, origem, vertice

    for (int i = 0; i < n; i++){
        if (s[i] == 'S'){
            dist[i] = 0;
            pq.push({0,i});
        }
    }

    while(!pq.empty()){
        auto [d, v] = pq.top();
        d = -d;
        pq.pop();
        if (d != dist[v]) continue;
        for (auto u : graph[v]){
            int  novadistancia = d + 1;
            if (novadistancia < dist[u]) {
                dist[u] = novadistancia;
                pq.push({-novadistancia, u});
            }
        }
    }
}

signed main(){
    winton;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    string s;
    cin >> s;
    djikstra(s);
    for (int i = 0; i < n; i++){
        debug(i, dist[i]);

    }    
    for (int i = 0; i < n; i++){
        if (s[i] == 'S') continue;
        int mn1 = INF, mn2 = INF;
        for (auto u : graph[i]){
            if (dist[u]+1 < mn1){
                mn2 = mn1;
                mn1 = dist[u]+1;
            } 
            else if (dist[u]+1 < mn2) mn2 = dist[u]+1;
        }
        cout << mn1+mn2 << endl;
    }
}


