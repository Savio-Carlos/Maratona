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

const int MAX = 3e5+7;
const int INF = LLONG_MAX;

struct edge {
    int to, cap, rev, flow;
};

int n;
vector<edge> graph[MAX];
vector<int> lev, beg;
int F;

bool bfs(int s, int t) {
    lev = vector<int>(n*n+2*n+2, -1); lev[s] = 0;
    beg = vector<int>(n*n+2*n+2, 0);
    queue<int> q; q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (auto& i : graph[u]) {
            if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
            lev[i.to] = lev[u] + 1;
            q.push(i.to);
        }
    }
    return lev[t] != -1;
}
int dfs(int v, int s, int f = INF) {
    if (!f or v == s) return f;
    for (int& i = beg[v]; i < graph[v].size(); i++) {
        auto& e = graph[v][i];
        if (lev[e.to] != lev[v] + 1) continue;
        int foi = dfs(e.to, s, min(f, e.cap - e.flow));
        if (!foi) continue;
        e.flow += foi, graph[e.to][e.rev].flow -= foi;
        return foi;
    }
    return 0;
}
int max_flow(int s, int t) {
    while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
    return F;
}
    
//guardar os nos do grid na posicao (i-1)*n + j
//guardar os nos linha na posicao n*n+i e os nos colunas na posicao n*n+n+j
//no source vai ser 0?
//no sink vai ser n*n + 2*n + 1?

signed main(){
    winton;
    cin >> n;
    
    int S = 0;//source
    int T = (n*n) + 2*n + 1;//sink

    int k = 0;

    vector<vector<int>> grid(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){

            int a = ((i-1)*n + j);
            int col = n*n + i; 
            int row = n*n + n + j; 
            
            cin >> grid[i][j];
            
            if (grid[i][j] == 0){
                graph[a].push_back({T, 1, graph[T].size(), 0});
                graph[T].push_back({a, 0, graph[a].size()-1, 0});

                graph[col].push_back({a, 1, graph[a].size(), 0});
                graph[a].push_back({col, 0, graph[col].size()-1, 0});

                graph[row].push_back({a, 1, graph[a].size(), 0});
                graph[a].push_back({row, 0, graph[row].size()-1, 0});
                
                k++;
            }
            else if (grid[i][j] > 1){
                graph[S].push_back({a, grid[i][j] - 1, graph[a].size(), 0});
                graph[a].push_back({S, 0, graph[S].size()-1, 0});

                graph[a].push_back({col, grid[i][j] - 1, graph[col].size(), 0});
                graph[col].push_back({a, 0, graph[a].size()-1, 0});

                graph[a].push_back({row, grid[i][j] - 1, graph[row].size(), 0});
                graph[row].push_back({a, 0, graph[a].size()-1, 0});
            }
        }
    }
    int x = max_flow(S,T);

    int cost = 2*k - x;
    cout << cost << endl;
}