#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) ((int)a.size())
#define endl '\n'
#define ll long long
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

const int MAX = 1e5+7;

vector<vector<int>> graph;
vector<int> leafs;

void dfs(int v, int p){
    if (graph[v].size() == 1) leafs.push_back(v);
    for(auto u : graph[v]){
        if (u == p) continue;
        dfs(u,v);
    }
}

void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main(){
    winton;
    setIO("kingdom");
    int n;
    cin >> n;
    graph.resize(n);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0, -1);
    if (n == 2){
        cout << 1 << endl;
        cout << 1 << " " << 2 << endl;
        return 0;
    }   
    int mid = leafs.size()/2;
    cout << mid + leafs.size()%2 << endl;

    if (leafs.size()&1){
        for (int i = 0; i < mid; i++){
            cout << leafs[i]+1 << " " << leafs[i+mid+1]+1 << endl;
            debug(i, mid);
        }
        cout << 1 << " " << leafs[mid]+1 << endl;
    }
    else {
        for (int i = 0; i < mid; i++){
            cout << leafs[i]+1 << " " << leafs[i+mid]+1 << endl;
        }
    }
}