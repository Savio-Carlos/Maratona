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

int n, q, timer = -1, tree[4*MAX], arr[MAX], tin[MAX], tout[MAX], flat[MAX];
vector<vector<int>> graph;
vector<int> euler, pathsum;

void dfs(int v, int p, int sum){
    euler.push_back(v);
    sum+=arr[v];
    pathsum.push_back(sum);
    tin[v] = ++timer;
    for (auto u : graph[v]){
        if (u != p) dfs(u,v, sum);
    }
    tout[v] = timer;
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
    cin >> n >> q;
    graph.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,0,0);
    build(1,0,n-1);
    while(q--){
        int op;
        cin >> op;
        if (op == 1){
            int s, x;
            cin >> s >> x;
            int novox;
            if (x < arr[s-1]) novox = - (arr[s-1] - x);
            else novox = x - arr[s-1];
            arr[s-1] = x;
            add(1,0,n-1, tin[s-1], tout[s-1], novox);
        }
        else {
            int s;
            cin >> s;
            cout << get(1,0,n-1, tin[s-1]) << endl;
        }
    }
}