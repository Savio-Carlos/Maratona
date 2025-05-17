#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

class graph { 
    vector<vector<pair<int,int>>> adj;// <from, <to, distance>>
    vector<int> gold, visited;
    int n, c;

public: 
    graph(int n, int c) : adj(n), gold(n), n(n), c(c), visited(n){}

    void setGold (int v, int g){
        gold[v] = g;
    }

    void addEdge (int from, int to, int dist){
        adj[from].push_back({to,dist});
        adj[to].push_back({from,dist});
    }

    pair<int,int> dfs(int v, int dist){//<dist,gold>
        visited[v] = 1;
        pair<int,int> ret;
        int gold_acumulado = gold[v];
        int distancia = dist;
        int dist_acumulada = 0;
        for (auto u : adj[v]){
            if (!visited[u.first]){
                pair<int,int> f = dfs(u.first, u.second);
                gold_acumulado += f.second;
                dist_acumulada += f.first;
            }
        }

        ret.first = (gold_acumulado+c-1)/c * (dist * 2) + dist_acumulada;
        ret.second = gold_acumulado;

        return ret;
    }
};

signed main() {
    winton;
    int n, c;
    cin >> n >> c;
    graph G(n,c);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        G.setGold(i,a);   
    }
    G.setGold(0,0);
    for (int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        G.addEdge(a-1, b-1, c);
    }
    pair<int,int> ans = G.dfs(0, 0);
    cout << ans.first << endl;
    
}

/*
        cout << "v: " << v << " ret.first: " << ret.first << " ret.second: " << ret.second << endl;
        cout << "distancia: " << distancia << endl;
        cout << div << endl;
        cout << gold_acumulado << endl;
        cout << c << endl;        
*/