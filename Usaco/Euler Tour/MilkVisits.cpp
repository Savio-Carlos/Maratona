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

int n, q, timer = 0, tin[MAX], depth[MAX];
vector<int> et;
pair<int,int> sp[MAX*2][LOG+1];
vector<vector<int>> graph; //0 indexado
vector<set<int>> sete(MAX);

void dfs(int v, int p){
    sete[v].insert(arr[v]);
    tin[v] = et.size();
    et.push_back(v);
    for (auto u : graph[v]){
        if (u!=p){
            dfs(u, v);
            depth[u] = depth[v] + 1;
            et.push_back(v);
            if (sete[u].size() > sete[v].size()) swap(sete[v], sete[u]);
            for (auto i : sete[u]) sete[v].insert[i];
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
    if (tinLCA[a] > tinLCA[b]) swap(a,b);
    return query(tinLCA[a], tinLCA[b]).second;
}

void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main(){
    setIO("milkvisit");
    winton;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    vector<int> anss;
    while(q--){
        int a, b, t;
        cin >> a >> b >> t;
        int mac = lca(--a,--b);
        int ans = sete[mac].find(t);
        anss.push_back(ans);
    }
}