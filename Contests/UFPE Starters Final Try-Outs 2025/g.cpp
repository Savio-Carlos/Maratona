#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int INF = 1e18+8;
const int MAXN = 2e5+7;
vector<pair<int, int>> graph[MAXN];
int dist[2][MAXN];

void dijkstra(int id, int st){
    for(int i = 0; i < MAXN; i++) dist[id][i] = INF;
    priority_queue<pair<int, int>> pq;
    //d, v
    pq.push({0, st});
    dist[id][st] = 0;
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[id][v] < d) continue;
        for(auto [u, w] : graph[v]){
            if(dist[id][u] > d + w){
                dist[id][u] = d + w;
                pq.push({-dist[id][u], u});
            }
        }
    }
}

signed main(){
    fastio;
    int n, m, q, x1, x2; cin >> n >> m >> q >> x1 >> x2;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    x1--, x2--;

    dijkstra(0, x2);
    dijkstra(1, x1);

    // for(int i = 0; i < n; i++){
    //     cout << dist[0][i] << " ";
    // }
    // cout << endl;

    // for(int i = 0; i < n; i++){
    //     cout << dist[1][i] << " ";
    // }
    // cout << endl;
    while(q--){
        int x; cin >> x;
        x--;
        if(x == x2){
            cout << 0 << endl;
            continue;
        }
        int d = dist[0][x];
        int d2 = dist[1][x] + dist[1][x2];
        cout << abs(d2 - d) << endl;
    }
    
}