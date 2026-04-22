#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int LOG = 20;

int n, m, q, timer = -1, arr[MAX], tin[MAX], tout[MAX], depth[MAX], pathsum[MAX], visited[MAX], ddist[42][MAX];
vector<vector<pair<int,int>>> graph;
pair<int,int> sp[MAX*2][LOG+1];
vector<int> euler;
set<pair<int,int>> bad_edges;

void dfs(int v, int p){
    visited[v] = 1;
    tin[v] = euler.size();
    euler.push_back(v);
    for (auto [to,w] : graph[v]){
        if (!visited[to]){
            pathsum[to] = pathsum[v] + w;
            depth[to] = depth[v]+1;
            dfs(to,v);
            euler.push_back(v);
            if (to <= v) bad_edges.erase({to,v});
            else bad_edges.erase({v,to});
        }
    }
    tout[v] = euler.size()-1;
}

void buildtable(){
    for (int i = 0; i < (int)euler.size(); i++){
        sp[i][0] = {depth[euler[i]], euler[i]};
    }
    for (int j = 1; j <= LOG; j++){
        for (int i = 0; i + (1<<(j-1)) < (int)euler.size(); i++){
            sp[i][j] = min (sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
        }
    }
}

pair<int,int> query (int a, int b){
    int len =  b - a + 1;
    int lg = 31 - __builtin_clz(len);
    return min(sp[a][lg], sp[b - (1<<lg) + 1][lg]);
}

int lca(int a, int b){
    if (tin[a] > tin[b]) swap(a,b);
    return query(tin[a], tin[b]).second;
}

void djikstra(int st, int ddist[MAX]){
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < n; i++)ddist[i]=LLONG_MAX;
    ddist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if (-d != ddist[v]) continue;
        for (auto [u,w] : graph[v]){
            long long nd = -d + w;
            if (nd < ddist[u]) {
                ddist[u] = nd;
                pq.push({-nd, u});
            }
        }
    }
}

signed main(){
    winton;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[--a].push_back({--b,w});
        graph[b].push_back({a,w});
    }
    for (int i = 0; i < n; i++){
        for (auto [t, w] : graph[i])
        if (i < t) bad_edges.insert({i,t});
    }   
    dfs(0,0);
    buildtable();
    int cpos = 0;
    for (auto [u,v] : bad_edges) {
        //cout << u << " " << v << endl;
        djikstra(u,ddist[cpos++]);
    }
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        int mac = lca(--a,--b);
        int ans = pathsum[a] + pathsum[b] - 2*pathsum[mac];
        for (int i = 0; i < bad_edges.size(); i++){
            ans = min(ans, ddist[i][a] + ddist[i][b]);
        }
        cout << ans << endl;
    }
}