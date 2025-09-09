//Subtree Queries 

const int MAXN = 2e5+7;

int tree[4*MAXN], tin[MAXN], tout[MAXN], flat[MAXN];
vector<vector<int>>graph;
int timer = 0;

void dfs(int v, int p){
    tin[v] = ++timer;
    for (auto u : graph[v]){
        if (u!=p){
            dfs(u, v);
        }
    }
    tout[v] = timer;
}

int build(int node, int l, int r){
    if (l == r){
        return tree[node] = flat[l];
    }
    int m = (l+r)/2;
    return tree[node] = build(node*2, l, m) + build(node*2+1, m+1, r);
}

int query (int node, int l, int r, int a, int b){
    if (b < l || r < a) return 0;
    if (l >= a && r <= b)  return tree[node];
    int m = (l+r)/2; 
    return query(node*2, l, m, a, b) + query(node*2+1, m+1, r, a, b);
}

void update(int node, int l, int r, int i, int x){
    if (i < l or i > r) return;
    if (l == r) {
        tree[node]=x;
        return;
    }
    int m = (l+r)/2;
    update(node*2, l, m, i, x);
    update(node*2+1, m+1, r, i, x);
    tree[node] = tree[node*2] + tree[node*2+1];
}

signed main(){
    int n, q;
    cin >> n >> q;
    vector<int>arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    graph.resize(n+1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,1);
    for (int i = 1; i <= n; i++){
        flat[tin[i]] = arr[i];
    }
    build(1,1,n);
    
    while(q--){
        int op;
        cin >> op;
        if (op == 1){
            int idx, valor;
            cin >> idx >> valor;
            update(1, 1, n, tin[idx], valor);
        }
        else {
            int s;
            cin >> s;

            int ans = query (1,1,n,tin[s], tout[s]);
            cout << ans << endl;
        }
        
    }
}