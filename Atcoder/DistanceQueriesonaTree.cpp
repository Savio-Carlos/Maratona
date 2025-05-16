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

int n, q, timer = -1, tree[4*MAX], arr[MAX], tin[MAX], tinLCA[MAX], tout[MAX], depth[MAX];
vector<vector<tuple<int,int,int>>> graph;
pair<int,int> sp[MAX*2][LOG+1];
vector<int> pathsum, euler;
map<int,int> mp;

void dfs(int v, int p, int sum){
    sum+=arr[v];
    pathsum.push_back(sum);
    tin[v] = ++timer;
    tinLCA[v] = euler.size();
    euler.push_back(v);
    for (auto [u, idx, w] : graph[v]){
        if (u != p) {
            depth[u] = depth[v]+1;
            arr[u] = w;
            mp[idx] = u;
            dfs(u,v, sum);
            euler.push_back(v);
        }
    }
    tout[v] = timer;
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
    if (tinLCA[a] > tinLCA[b]) swap(a,b);
    return query(tinLCA[a], tinLCA[b]).second;
}

void build(int node, int l, int r){
    if (l == r){
        tree[node] = pathsum[l];
        return;
    }
    int m = (l+r)/2;
    build(node*2, l, m);
    build(node*2+1, m+1, r);
}

int get(int node, int l, int r, int i){
    if (l == r) return tree[node];
    int m = (l+r)/2;
    int res;
    if (i > m) res = get(node*2+1, m+1, r, i);
    else res = get(node*2, l, m, i); 
    return res + tree[node];
}

void add(int node, int l, int r, int a, int b, int x){
    if(b < l or r < a) return;
    if(a <= l && r <= b){
        tree[node] += x;
        return;
    }
    int m = (l+r)/2;
    add(2*node, l, m, a, b, x);
    add(2*node+1, m+1, r, a, b, x);
}
signed main() {
    winton;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n-1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[--a].push_back({--b, i, w});
        graph[b].push_back({a,i,w});
    }
    cin >> q;
    dfs(0,0,0);
    build(1,0,n-1);
    buildtable();
    while(q--){
        int op;
        cin >> op;
        if (op == 1){
            int s, x;
            cin >> s >> x;
            s--;
            int child = mp[s];
            int delta = x - arr[child];
            arr[child] = x;    
            add(1, 0, n-1, tin[child], tout[child], delta);
        }
        else {  
            int u, v;
            cin >> u >> v;
            --u;--v;
            int mac = lca(u,v);
            cout << get(1,0,n-1,tin[u]) + get(1,0,n-1,tin[v]) - 2* get(1,0,n-1,tin[mac]) << endl;
        }
    }
}