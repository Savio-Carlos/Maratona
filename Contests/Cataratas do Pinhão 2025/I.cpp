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
const int INF = 1e18;
const int MAXP = 22;
const int TEMPO = 960;

vector<vector<pair<int,int>>> graph; 
int n, m, p, f[MAXP], t[MAXP];
    
vector<int> djikstra(int st){
    vector<int> dist(MAX, INF);
    priority_queue<pair<int,int>> pq;
    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()){
        auto [d, v] = pq.top();
        d = -d;
        pq.pop();
        if (d != dist[v]) continue;
        for (auto [u,w] : graph[v]){
            int  novadistancia = d + w;
            if (novadistancia < dist[u]) {
                dist[u] = novadistancia;
                pq.push({-novadistancia, u});
            }
        }
    }
    return dist;
}

signed main(){
    winton;
    cin >> n >> m >> p;
    graph.resize(n);
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[--a].emplace_back(--b,c);
        graph[b].emplace_back(a,c);
    }
    for (int i = 0; i < p; i++) cin >> f[i];
    for (int i = 0; i < p; i++) cin >> t[i];
    
    vector<int> sts;
    sts.push_back(n-1);
    for (int i = 0; i < p; i++) sts.push_back(i);

    vector<vector<int>> dist(p+1, vector<int> (p+1));
    for (int i = 0; i <= p; i++){
        int st = sts[i];
        vector<int> cur = djikstra(st);
        for (int j = 0; j <= p; j++){
            dist[i][j] = cur[sts[j]];
        }
    }

    vector<vector<int>> dp((1 << p), vector<int> (p, INF));

    for (int i = 0; i < p; i++){
        dp[1<<i][i] = dist[0][i+1] + t[i];
    }

    for (int mask = 1; mask < (1 << p); mask++){//mask dos pontos visitados
        for (int i = 0; i < p; i++){
            if (!((1 << i) & mask)) continue;//se essa posicao e 0 n considero pra essa mask
            for (int j = 0; j < p; j++){    
                if (((1 << j) & mask)) continue;//se essa posicao e 1, eu ja visitei esse ponto entao n tem como ir pra ele dnv
                int target_mask = mask | (1 << j);//mask atual + ponto que quero ir
                dp[target_mask][j] = min(dp[target_mask][j], dp[mask][i] + dist[i+1][j+1] + t[j]);
                //dp [onde vou][ponto da onde vim] = min(todos os possiveis pontos de partida j que posso ter saido da mask e ido para target mask)
            }
        }
    }

    int ans = 0;

    for(int mask = 1; mask < (1 << p); mask++){
        bool pos = false;
        for (int i = 0; i < p; i++){
            if (mask & (1 << i))
            if (dp[mask][i] <= TEMPO) pos = true;//se algum ponto final tiver tempo total menor que o limite entao e possivel fazer essa mask
        }
        if (pos){
            int sum = 0;
            for (int i = 0; i < p; i++){
                if (mask & (1 << i)) sum += f[i];
            }
            ans = max(ans,sum);
        }
    }
    cout << ans << endl;
}