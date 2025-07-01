#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = LLONG_MAX;
/*
uma arvore tem n-1 arestas
o objetivo e fazer todas as arestas terem apenas um caminho, com excessao de uma aresta que vai ter dois
para garantir isso, para cada no eu vejo a relacao dele com o vizinho, se era u -> v, entao a proxima edge tem que ser v <- y
vou alternando os nos de modo que um no recebe as ligacoes, e todos os seus vizinhos enviam, entao cada vizinho vai enviar todas suas ligacoes
depois eu vejo como formar o 1 caminho faltando
na verdade como e uma arvore isso sempre acontece
para criar um caminho extra eu preciso de um no que so tenha um outro no chegando nele, e que esse no tenha um filho que nao tenha nenhuma conexao
*/

vector<vector<int>> graph;
vector<pair<int,int>> ans;

void dfs(int v, int p, bool t){
    for (auto u : graph[v]){
        if (u == p) continue;
        if (t) ans.push_back({v,u});
        else ans.push_back({u,v});
        dfs(u,v,!t);
    }
}

void solve(){
    int n;
    cin >> n;
    graph.resize(n);
    ans.clear();
    for (int i = 0; i < n; i++){
        graph[i].clear();
    }
    map<int,int> conn;
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
        conn[a]++;
        conn[b]++;
    }
    if (n == 2) {
        cout << "NO" << endl;
        return;
    }
    dfs(0,-1,1);
    for (auto [u,v] : ans) cout << u+1 << " " << v+1 << endl;
    // bool pos = false;
    // if (pos) cout << "YES" << endl;
    // else cout << "NO" << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}