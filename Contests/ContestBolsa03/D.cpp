#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXS = 1e5+7;

class graph {
    vector<int> dist, visited;
    vector<vector<int>> adj;
    int n, st, en;
public:
    graph(int n, int st,int en) : n(n), st(st), en(en), visited(n), adj(n){}

    void addEdge(int from , int to){
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    void dfs(int v, int d){
        visited[v] = 1;
        for (auto u : adj[v]){
            if (!visited[u]){
                dfs(u,d+1);
            }
        }
        dist.push_back(v);
    }

    void solve(){
        dfs(en,0);

        for (int i = 0; i < n; i++){
            cout << dist[i]+1 << " ";
        }
        cout << endl;
    }
};

signed main () {
    winton;
    int t;
    cin >> t;
    while (t--){
        int n, st, en;
        cin >> n >> st >> en;
        graph G(n,st-1,en-1);

        for (int i = 0; i < n-1; i++){
            int a, b;
            cin >> a >> b;
            G.addEdge(a-1,b-1);
        }
        G.solve();
    }
}