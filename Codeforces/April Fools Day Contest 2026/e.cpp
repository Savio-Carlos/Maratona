#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)


const int MAX = 1e4;
vector<pair<int,int>> graph[MAX]; 

int dist[MAX];


signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    priority_queue<pair<int,int>> pq;
    for (int i = 1; i <= n; i++)dist[i]=1e10;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d, v] = pq.top();
        d = -d;
        pq.pop();
        if (d != dist[v]) continue;
        for (auto [u,w] : graph[v]){
            int  novadistancia = d + w;
            if (novadistancia < dist[u]) {
                dist[u] = novadistancia;
                pq.push({-novadistancia, u});
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (dist[i] == 1e10) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
}