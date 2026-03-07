#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

const int INF = 1e18;
const int MAX = 5e5+7;

vector<tuple<int,int,int>> graph[MAX][3];
int dist[MAX][3];

void djikstra(){
    priority_queue<tuple<int,int,int>> pq;
    for (int i = 0; i < MAX; i++) dist[i][0] = dist[i][1] = dist[i][2] = INF;
    dist[1][0] = 0;
    pq.push({0,1,0});
    while(!pq.empty()){
        auto [d, v, id] = pq.top();
        d = -d;
        pq.pop();
        if (d != dist[v][id]) continue;
        for (auto [u,w,nid] : graph[v][id]){
            int nd = d + w;
            if (nd < dist[u][nid]){
                dist[u][nid] = nd;
                pq.push({-nd, u, nid});
            }
        }
    }
}

signed main(){
    fastio;
    int n, c, p;
    cin >> n >> c >> p;
    for (int i = 0; i < c; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][1].push_back({b,c,1});
    }
    for (int i = 1; i <= n; i++){
        graph[i][0].push_back({i,0,1});

        graph[i][1].push_back({i,0,2});
    }
    for (int i = 0; i < p; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][0].push_back({b,c,0});
        graph[b][0].push_back({a,c,0});

        graph[a][2].push_back({b,c,2});
        graph[b][2].push_back({a,c,2});
    }
    djikstra();
    cout << dist[n][2] << endl;

}