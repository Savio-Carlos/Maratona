#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXL = 1e9+7;

class grafo {
public:
    int n;
    int start, end;
    vector<int> perm;
    vector<int> dist;
    vector<vector<int>> matAdj;
    grafo(int n, int st, int en) : n(n), start(st), end(en), matAdj(n+1, vector<int>()), perm(n), dist(n+1, -1) {}

    void addAresta(int u, int v) {
        matAdj[u].push_back(v);
        matAdj[v].push_back(u);
    }

    void bfs() {
        queue<int> q;
        dist[end] = 0;
        q.push(end);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for (int u : matAdj[cur]){
                if(dist[u] == -1){
                    dist[u] = dist[cur] + 1;
                    q.push(u);
                }
            }
        }
    }
    void solve() {
        for (int i = 0; i < n; i++){
            perm[i] = i + 1;
        }
        sort(perm.begin(), perm.end(), [&](int a, int b){if(dist[a] == dist[b])return a < b;return dist[a] > dist[b]; });
        if(perm[n-1] != end){
            for (int i = 0; i < n-1; i++){
                if(perm[i] == end){
                    swap(perm[i], perm[n-1]);
                    break;
                }
            }
        }
        for (auto i : perm) cout << i << " ";
        cout << endl;
    }
};

signed main(){ _ 
    int t; 
    cin >> t;
    while(t--){
        int n, st, en;
        cin >> n >> st >> en;
        grafo G(n, st, en);
        for (int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            G.addAresta(u, v);
        }
        G.bfs();
        G.solve();
    }
}
