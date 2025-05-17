#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;

int visited[MAX];
set<int> convidados;
vector<vector<int>> graph;


int dfs(int v){
    visited[v] = 1;
    int cur = 0;
    for (auto u : graph[v]){
        if (!visited[u]){
            if (dfs(u)) cur++;
        }
        if (cur >= 2){
            convidados.insert(v);
        } 
    }
    //cout << v << " cur: " << cur << endl;
    if (convidados.count(v)) cur++;
    return (cur);
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        graph[--a].push_back(i);
        graph[i].push_back(a);
    }
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        convidados.insert(--a);
    }
    dfs(0);
    cout << convidados.size() << endl;
    for (auto u : convidados) cout << u+1 << " ";
}