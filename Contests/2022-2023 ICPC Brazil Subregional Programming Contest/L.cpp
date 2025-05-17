#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+14;

int arr[MAX], total[MAX]; 
map<pair<int,int>, int> answers;
vector<vector<int>> graph;

struct node{
    map<int,int> freq;
    int sum = 0;  
};

node &merge (node &pai, node &filho){
    if (pai.freq.size() < filho.freq.size()) swap(filho,pai);
    for (auto &[c,q] : filho.freq){
        pai.sum -= pai.freq[c] * (total[c] - pai.freq[c]); 
        pai.freq[c] += q;
        pai.sum += pai.freq[c] * (total[c] - pai.freq[c]); 
    }
    return pai;
}

node dfs(int v, int p){
    node cur;
    for (auto u : graph[v]){
        if (u == p) continue;
        node filho = dfs(u,v);
        cur = merge(cur,filho);
    }
    cur.sum -= cur.freq[arr[v]] * (total[arr[v]] - cur.freq[arr[v]]);
    cur.freq[arr[v]]++;
    cur.sum += cur.freq[arr[v]] * (total[arr[v]] - cur.freq[arr[v]]);
    
    answers[{p,v}] = cur.sum;
    return cur;
}

signed main(){
    winton;
    int n;  
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];  
        total[arr[i]]++;
    } 
    vector<pair<int,int>> edges(n-1);
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
        edges[i] = {a,b};
    }
    dfs(0,-1);
    // for (auto [u,v] : arestas){
    //     cout << u.first << " " << u.second << " " << v << endl;
    // }
    dfs(0,-1);
    for (int i = 0; i < n-1; i++){
        cout << max(answers[edges[i]], answers[{edges[i].second, edges[i].first}]) << " ";
    }

}

/*

ll n;
map<ll, ll> totfreq;
v64 colors;
vector<v64> g;
map<p64, ll> ans;

struct P {
    map<ll, ll> freq;
    ll sum = 0;
};

P& merge(P& a, P& b) {
    if (a.freq.size() < b.freq.size()) swap(a, b);

    for(auto& [k, v] : b.freq) {
        a.sum -= a.freq[k] * (totfreq[k] - a.freq[k]);
        a.freq[k] += v;
        a.sum += a.freq[k] * (totfreq[k] - a.freq[k]);
    }
    return a;
}

P dfs(ll u, ll parent) {
    P curr;
    ll visited = 0;
    for (auto v : g[u]) {
        if (v == parent) continue;
        visited++;
        P ret = dfs(v, u);
        curr = merge(curr, ret);
    }

    curr.sum -= curr.freq[colors[u]] * (totfreq[colors[u]] - curr.freq[colors[u]]);
    curr.freq[colors[u]]++;
    curr.sum += curr.freq[colors[u]] * (totfreq[colors[u]] - curr.freq[colors[u]]);
    
    ans[{parent, u}] = curr.sum;
    return curr;
}

int main(){
    _;
    cin >> n;
    colors.resize(n);
    forn(i, 0, n) cin >> colors[i], totfreq[colors[i]]++;
    g.resize(n);
    vector<p64> edges(n-1);
    forn(i, 0, n-1) {
        ll u, v; cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);
    forn(i, 0, n-1) {
        ll resp = max(ans[edges[i]], ans[{edges[i].second, edges[i].first}]);
        cout << resp << " \n"[i==n-2];
    }
    return 0;
}
    */