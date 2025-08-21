#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAXN = 100+7;
const int MAXM = 1e4+7;
const int INF = 1e18;

int n, m, s, t, ciclo;
int d[MAXN], w[MAXM], p[MAXN], visited[MAXN]; 
pair<int, int> arestas[MAXM];
vector<int> graph[MAXN];

bool bellmanford(int st){
    for(int i = 0; i < MAXN; i++) d[i] = INF;
    d[st] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            auto &[a, b] = arestas[j];
            if(!visited[b]) continue;
            if(d[b] > d[a] + w[j]){
                if(i == n){
                    ciclo = a;
                    return 1;
                }
                d[b] = d[a] + w[j];
            }
        }
    }
    return 0;
}

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

signed main(){
    winton;
    cin >> n >> m >> s >> t; 
    for(int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        a--, b--;
        w[i] = cost;
        arestas[i] = {a, b};
        graph[a].push_back(b);
    }

    for(int i = 0; i < n; i++) cin >> p[i];
    
    for(int i = 0; i < m; i++){
        auto [a, b] = arestas[i];
        w[i] -= p[b];
    }

    s--, t--;
    dfs(s);
    if(bellmanford(s)){ 
        memset(visited, 0LL, sizeof(visited));
        dfs(ciclo);
        if(visited[t]) cout << "Money hack!\n";
        else if(d[t] != INF) cout << -d[t] << "\n";
        else cout << "Bad trip\n";
    }else if(d[t] != INF){
        cout << -d[t] << "\n";
    }else cout << "Bad trip\n";
}
