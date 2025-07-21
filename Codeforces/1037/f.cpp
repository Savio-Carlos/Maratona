#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

vector<vector<pair<int,int>>> graph;
vector<map<int,int>> mp(MAX);
vector<pair<int,int>> ancestor;
int same = 0, colors[MAX];

void dfs(int v, int p){
    for (auto &[u,c] : graph[v]){
        if (u==p) continue;
        ancestor[u] = {v,c};
        mp[v][colors[u]] += c;
        dfs(u,v);
    }
    same += mp[v][colors[v]];
}

void solve(){
    int n, q;
    cin >> n >> q;
    same = 0;
    int sum = 0;
    graph.resize(n);
    ancestor.resize(n);
    for (int i = 0; i < n; i++){
        graph[i].clear();
        mp[i].clear();
        ancestor[i] = {-1,0};
        colors[i] = 0;
    }
    for (int i = 0; i < n; i++) cin >> colors[i];
    for (int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        sum += c;
        graph[--a].push_back({--b,c});
        graph[b].push_back({a,c});
    }
    dfs(0,0);
    //debug(sum);
    while(q--){
        int v, cor;
        cin >> v >> cor;
        v--;
        if (v != 0){
            auto &[pai,c] = ancestor[v]; //pego a conexao do meu pai comigo
            same -= mp[pai][colors[pai]]; // tiro da resposta a soma de todas as conexoes do meu pai com caras com a mesma cor que ele
            mp[pai][colors[v]] -= c; //tiro da soma de todas as conexoes do meu pai com caras com a mesma cor que ele o custo de ir para a aresta v
            mp[pai][cor] += c; // adiciono na soma das conexoes do meu pai com caras com a mesma nova cor o custo de ir para v (ja que v agora e dessa cor)
            same += mp[pai][colors[pai]]; // adiciono na resposta a soma das conexoes do meu pai com caras da mesma cor que ele (agora atualizado)
        }
        same -= mp[v][colors[v]];//tiro da resposta a soma das minhas conexoes com minha cor
        same += mp[v][cor]; // adiciono na resposta a soma das minhas conexoes com a nova cor
        colors[v] = cor;
        cout << sum - same << endl;
    }
    
}

signed main() {
    winton;
    int t;
    cin >> t;
    while (t--) solve();
}