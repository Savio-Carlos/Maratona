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

int n, q, depth[MAX], dist[3][MAX];
vector<int> path, answers;
vector<vector<int>> graph;
map<int, vector<pair<int,int>>> queries;

void dfs(int v, int p, int id){
    for (auto u : graph[v]){
        if (u != p){
            dist[id][u] = dist[id][v] + 1;
            dfs(u,v,id);
        }
    }
}

void dfs2(int v, int p){
    for (auto [k, idx] : queries[v]){
        if (k <= path.size()){
            answers[idx] = path[path.size() - k] + 1;
        }
        //else answers[idx] = -1;
    }
    path.push_back(v);
    for (auto u : graph[v]){
        if (u!=p){
            dfs2(u,v);
        }
    }
    path.pop_back();
}

int distance(int id){
    int u = -1, mx = 0;
    for (int i = 0; i < n;i++){
        if (dist[id][i] > mx){
            u = i;
            mx = dist[id][i];
        }
    }
    return u;
}

signed main(){
    winton;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    cin >> q;
    answers.resize(q);
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries[--a].push_back({b,i});
    }

    dfs(0,-1,0);
    int l = distance(0);
    dfs(l,-1,1);
    int r = distance(1);
    dfs(r,-1,2);
    for (int st : {l,r}){
        dfs2(st,-1);
        path.clear();
    }
    for (auto u : answers) {
        if (u) cout << u << endl;
        else cout << "-1" << endl;
    }
}