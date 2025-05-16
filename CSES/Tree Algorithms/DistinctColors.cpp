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

int n, q, timer = -1, tree[4*MAX], arr[MAX], tin[MAX], tout[MAX], answers[MAX];
vector<vector<int>>graph;
vector<int> euler;
map<int,int> last;

void dfs(int v, int p){
    tin[v] = ++timer;
    euler.push_back(v);
    for (auto u : graph[v]){
        if (u!=p){
            dfs(u, v);
        }
    }
    tout[v] = timer;
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

int query(int node, int l, int r, int a, int b){
    if(b < l or r < a) return 0;
    if(a <= l and r <= b) {
        //cout << "node: " << node << " l: " << l << " r: " << r << " a: " << a << " b: " << b  << " valor: " << tree[node]<< endl;
        return tree[node];
    
    }
        int m = (l+r)/2;
    return query(2*node, l, m, a, b) + query(2*node+1, m+1, r, a, b);
}


signed main() {
    winton;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,0);
    //for (int i = 0; i < n; i++){cout<<euler[i]<<" ";}cout<<endl;
    for (int i = n-1; i >= 0; i--){
        int cur = arr[euler[i]];
        if (last.count(cur) != 0){
            update(1,0,n-1, last[cur], 0);
        }
        update(1,0,n-1,i,1);
        last[cur] = i;
        answers[euler[i]] = query(1,0,n-1, tin[euler[i]], tout[euler[i]]);
    }
    for (int i = 0; i < n; i++){
        cout << answers[i] << " ";
    }
}