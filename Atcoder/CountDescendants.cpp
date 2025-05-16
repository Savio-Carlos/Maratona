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

int n, q, timer = -1, tree[4*MAX], tin[MAX], tout[MAX];
vector<int> graph[MAX], depth;
map<int,vector<int>> mp;

void dfs(int v, int p){
    tin[v] = ++timer;
    mp[depth[v]].push_back(v);
    for (auto u : graph[v]){
        if (u!=p){
            depth[u] = depth[v] + 1;
            dfs(u,v);
        }
    }
    tout[v] = timer;
}

int query(int node, int l, int r, int a, int b){
    if(b < l or r < a) return 0;
    if(a <= l and r <= b) {
        //cout << "node: " << node << " l: " << l << " r: " << r << " a: " << a << " b: " << b  << " valor: " << tree[node]<< endl;
        return tree[node];
    
    }
        int m = (l+r)/2;
    return query(2*node, l, m, a, b) + query(2*node+1, m+1, r, a, b);
}

void update(int node, int l, int r, int i, int x){
    if(i < l or r < i) return;
    if(l == r){
        tree[node] = x;
        return;
    }
    int m = (l+r)/2;
    update(2*node, l, m, i, x);
    update(2*node+1, m+1, r, i, x);
    tree[node] = tree[2*node] + tree[2*node+1];
}

signed main(){
    winton;
    cin >> n;
    depth.resize(n+1);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        graph[--a].push_back(i);
        graph[i].push_back(a);
    }
    cin >> q;
    map<int,vector<pair<int,int>>> queries;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries[b].push_back({--a,i});
    }
    dfs(0,0);
    int maxdepth = *max_element(depth.begin(), depth.end());
    vector<int> ans(q);
    for (int i = 0; i <= maxdepth; i++){
        for (auto u : mp[i]){
            update(1,0,n-1,tin[u],1);
        }
        for (auto [sbt,idx] : queries[i]){
            ans[idx] = query(1,0,n-1,tin[sbt],tout[sbt]);
        }
        for (auto u : mp[i]){
            update(1,0,n-1,tin[u],0);
        }
    }
    for (auto u : ans) cout << u << endl;
}