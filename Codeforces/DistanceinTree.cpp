#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 5e4+7;
const int LOG = 20;

int n, timer = 0, tin[MAX], depth[MAX];
vector<int> et;
pair<int,int> sp[MAX*2][LOG+1];
vector<vector<int>> graph; //0 indexado

void dfs(int v, int p){
    tin[v] = et.size();
    et.push_back(v);
    for (auto u : graph[v]){
        if (u!=p){
            depth[u] = depth[v]+1;
            dfs(u,v);
            et.push_back(v);
        }
    }
}

void buildtable(){
    for (int i = 0; i < (int)et.size(); i++){
        sp[i][0] = {depth[et[i]], et[i]};
    }
    for (int j = 1; j <= LOG; j++){
        for (int i = 0; i + (1<<(j-1)) < (int)et.size(); i++){
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

signed main() {
    winton;
    int k;
    cin >> n >> k;
    graph.resize(n);
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,0);
    buildtable();
    int ans = 0;
    map<int,int> mp;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int mac = lca(i,j);
            int dist = depth[i] + depth[j] - 2*depth[mac];
            if (dist == k) ans++;
        }
    }
    cout << ans << endl;
}
