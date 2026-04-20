#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

namespace dbg {
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
        cerr << s.substr(0, cpos) << " = " << h;
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
    #define debug(...) cerr << "[" << __func__ << ":" << __LINE__ << "]" << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 1e3+7;

vector<int> graph[MAX];
int visited[MAX], dir[MAX];

signed main(){
    winton;
    int n;
    cin >> n;
    vector<tuple<int,int,int>> gears(n);
    
    for (auto &[x,y,r] : gears) cin >> x >> y >> r;
    
    for (int i = 0; i < n - 1; i++){
        auto [xi, yi, ri] = gears[i];
        for (int j = i + 1; j < n; j++){
            auto [xj, yj, rj] = gears[j];
            
            int dx = (xi - xj) * (xi - xj);
            int dy = (yi - yj) * (yi - yj);
            int reach = (ri + rj) * (ri + rj);
            if (reach >= dx + dy){
                graph[i].push_back(j);
                graph[j].push_back(i);
                // debug(i,j);
            }
        }
        // debug(graph[i]);
    }
    
    bool pos = true;

    function<void(int, int, int)> dfs = [&](int v, int p, bool d) {
        visited[v] = 1;
        dir[v] = d;
        for (auto u : graph[v]){
            if (u == p) continue;
            if (visited[u] && dir[u] == dir[v]){
                pos = false;
                break;
            } 
            if (!visited[u]) dfs(u,v,!d);
        }
    };
    dfs(0,-1,0);

    if (!pos || !visited[n-1]){
        if (!pos) cout << "The input gear cannot move." << endl;
        else if (!visited[n-1]) cout << "The input gear is not connected to the output gear." << endl;
        return 0;
    }
    int r1 = get<2>(gears[0]);
    int r2 = get<2>(gears[n-1]);
    debug(r1,r2);
    int g = gcd(r1,r2);
    if (dir[0] != dir[n-1])cout << "-";
    
    cout << r1/g << ":" << r2/g << endl;
}

