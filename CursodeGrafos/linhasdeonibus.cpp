#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+7;

map<int, vector<int>> linhas;
vector<vector<int>> graph;
vector<int> d;
//grafo condensado
//separar os diferentes componentes conexos e fazer um map para eles
//fazer um grafo onde cada elemento e um componente conexo, entao por exemplo a linha 1 chega direto na linha 3 mas precisa de um intermediario para chegar na linha 2

void dijkstra(vector<int>& start) {
    queue<int> q;
    for (int s : start) {
        d[s] = 1;
        q.emplace(s);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for (auto u : graph[cur]){
            if(d[u] > d[cur]+1){
                d[u] = d[cur]+1;
                q.emplace(u);  
            }   
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, L, s, e;
    cin >> T >> L >> s >> e;
    d.resize(L+1, INF);
    graph.resize(L+1);

    for(int i = 1; i <= L; i++){  
        int n; cin >> n;
        
        for(int j = 0; j < n; j++){
            int a; cin >> a;
            linhas[a].push_back(i);
            if (!linhas.empty()){
                for (auto u : linhas[a]){
                    if (i!=u){
                        graph[i].push_back(u);
                        graph[u].push_back(i);
                    }
                }
            }
        }
    }
    int ans = INF;
    dijkstra(linhas[s]);
    for (auto end : linhas[e]){
        ans = min(ans,d[end]);
    }
    cout << ans << endl;
}