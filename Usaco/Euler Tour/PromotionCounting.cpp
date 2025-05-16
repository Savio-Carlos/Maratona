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

/*
montar a segtree de acordo com o tempo de entrada
depois para cada cara, comecando do maior, verificar quantos 1's ativos no range da sua subarvore na segtree
depois marcar o lugar daquele no com 1
*/

int n, q, timer = -1, arr[MAX], tin[MAX], tout[MAX], tree[4*MAX];
vector<int> euler;
vector<vector<int>> graph;
void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void dfs(int v, int p){
    euler.push_back(arr[v]);
    tin[v] = ++timer;
    for (auto u : graph[v]){
        if(u!=p){
            dfs(u,v);
        }
    }
    tout[v] = timer;
}

int build(int node, int l, int r){
    if (l == r){
        return tree[node] = 0;
        //cout << l <<"l - node" << node << " valor: "<< flat[l] << " tin: " << tin[l] << endl;
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
    setIO("promote");
    winton;
    vector<pair<int,int>> queries;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        queries.push_back({arr[i],i});
    }
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    dfs(0,0);
    build(1,0,n-1);
    sort(rall(queries));
    vector<int> ans(n);
    for (auto [value, node] : queries){
        ans[node] = query(1,0,n-1,tin[node], tout[node]);
        update(1,0,n-1, tin[node], 1);
    }
    for (auto y : ans) cout << y << endl;
}

