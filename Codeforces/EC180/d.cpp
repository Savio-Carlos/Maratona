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
achar alguem 2-0 com um filho 0-1 ou 0-2 com um filho 1-0
*/

vector<vector<int>> graph;
set<pair<int,int>> ans;
int indeg[MAX], outdeg[MAX];
bool pos = false;

void dfs(int v, int p, bool t){
    for (auto u : graph[v]){
        if (u == p) continue; 
        if (t){
            ans.insert({v,u});
        } 
        else{
            ans.insert({u,v});
        } 
        dfs(u,v,!t);    
    }
}

void solve(){
    int n;
    cin >> n;
    graph.resize(n);
    ans.clear();
    pos = false;
    for (int i = 0; i < n; i++){
        graph[i].clear();
        indeg[i] = outdeg[i] = 0;
    }
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    int root1 = -1, root2 = -1, pai = -1;
    bool found = false;
    for (int i = 0; i < n; i++){
        if (graph[i].size() == 2){
            root1 = graph[i][0];
            root2 = graph[i][1];
            pai = i;
            found = true;
            ans.insert({root1,pai});
            ans.insert({pai,root2});
        }
        if(found) break;
    }
    if (n == 2 || !found) {
        cout << "NO" << endl;
        return;
    }
    dfs(root1,pai,1);
    dfs(root2,pai,0);
    cout << "YES" << endl;
    for (auto [u,v] : ans) cout << u+1 << " " << v+1 << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}