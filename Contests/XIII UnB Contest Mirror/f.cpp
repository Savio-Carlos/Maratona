#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int INF = 1e3;
const int MAXN = 103;
vector<int> graph[MAXN];


signed main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.push_back({a, b});
    }
    vector<int> res(n, n+1);
    for(auto [a, b] : edges){

        queue<int> q;
        q.push(a);
        vector<int> dist(n, -1);
        vector<int> parent(n, -1);
        dist[a] = 0;
        while(!q.empty()){
            auto v = q.front(); q.pop();

            for(auto u : graph[v]){
                if((u == a && v == b) || (u == b && v == a)) continue;
                if(dist[u] == -1){
                    dist[u] = dist[v]+1;
                    parent[u] = v;
                    q.push(u);
                }
            }
        }

        if(dist[b] != -1){
            int v = b;
            int len = dist[v]+1;
            while(v != -1){
                res[v] = min(res[v], len);
                v = parent[v];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(res[i] == n+1) ans += (i+1);
        else ans += (i+1)*(res[i]);
    }
    cout << ans << endl;
}