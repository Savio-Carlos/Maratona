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

int n, q, timer = -1, arr[MAX], depth[MAX], parent[MAX], tinLCA[MAX], tin[MAX], tout[MAX], tree[4*MAX];
vector<int> pathxor, et;//indice e xorsomado
pair<int,int> sp[MAX*2][LOG+1];
vector<vector<int>> graph;

// 1) Euler tour to fill tin/tout and path‑xor prefix
// 2) Precompute RMQ (or binary‐lift) for LCA
// 3) Fenwick for range‐update point‐query
// 4) Process Q queries

void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void dfs(int v, int p, int xoracc){
    xoracc^=arr[v];
    parent[v] = p;
    pathxor.push_back(xoracc);
    tin[v] = ++timer;
    tinLCA[v] = et.size();
    et.push_back(v);
    for (auto u : graph[v]){
        if (u != p) {
            depth[u] = depth[v]+1;
            dfs(u,v, xoracc);
            et.push_back(v);
        }
    }
    tout[v] = timer;
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

void build(int node, int l, int r){
    if (l == r){
        tree[node] = pathxor[l];
        return;
    }
    int m = (l+r)/2;
    build(node*2, l, m);
    build(node*2+1, m+1, r);
}

void add(int node, int l, int r, int a, int b, int x){
    if(b < l or r < a) return;
    if(a <= l && r <= b){
        tree[node] ^= x;
        return;
    }
    int m = (l+r)/2;
    add(2*node, l, m, a, b, x);
    add(2*node+1, m+1, r, a, b, x);
}

int get(int node, int l, int r, int i){
    if (l == r) return tree[node];
    int m = (l+r)/2;
    int res;
    if (i > m) res = get(node*2+1, m+1, r, i);
    else res = get(node*2, l, m, i); 
    return res ^ tree[node];
}

signed main(){
    setIO("cowland");
    winton;
    cin >> n >> q;
    graph.resize(n);
    for (int i = 0; i < n; i++) cin>>arr[i];
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0,-1,0);
    build(1,0,n-1);
    buildtable();
    //for (int i = 0; i < 2*n; i++){cout << tree[i] << " ";}cout<<endl;
    while (q--){
        int op;
        cin >> op;
        if (op == 1){
            int s, x;
            cin >> s >> x;
            //cout << tin[s-1] << " tout: " << tout[s-1] << endl;
            int novox = x ^ arr[s-1];
            arr[s-1] = x;
            add(1,0,n-1, tin[s-1], tout[s-1], novox);
            //for (int i = 0; i < 2*n; i++){cout << tree[i] << " ";}cout<<endl;
        }
        else {
            int a, b;
            cin >> a >> b;
            a--;b--;
            int mac = lca(a,b);
            //cout << "LCA: " << mac << endl;
            // cout << "xor a: " << get(1, 0, n-1, tin[a]) << endl;
            // cout << "xor b: " << get(1, 0, n-1, tin[b]) << endl;
            // cout << "xor mac: " << get(1, 0, n-1, tin[mac]) << endl;
            // cout << "pai: " << parent[mac] << endl;
            if (parent[mac] != -1){
                cout << (get(1, 0, n-1, tin[a]) ^ get(1, 0, n-1, tin[b]) ^ get(1, 0, n-1, tin[mac]) ^ get(1, 0, n-1, tin[parent[mac]])) << endl;
            }
            else cout << (get(1, 0, n-1, tin[a]) ^ get(1, 0, n-1, tin[b]) ^ get(1, 0, n-1, tin[mac])) << endl;    
        }
    }
}