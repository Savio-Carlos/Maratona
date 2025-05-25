#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

int n, dist[MAX][2], visited[MAX];
vector<vector<pair<int,int>>> graph;

bool djikstraK(vector<pair<int,int>> &st, int id){
    priority_queue<pair<int,int>> pq;
    for (auto u : st){
        pq.push({-u.first, u.second});
        dist[u.second][id] = -u.first;
    }

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        // cout << -d << " ENTRO " << v << endl;
        // cout << dist[v][id] << endl;
        if (dist[v][id] < -d) continue;
        //cout << "distancia do K: " <<  dist[v][1] << " distancia atual: " << -d << " node: " << v << endl;
        
        for (auto [u,w] : graph[v]){
            if (id == 1) w*=2;
            int nd = -d+w;
            if (id == 0 && (dist[u][1] < nd)) continue;
            if (dist[u][id] > nd){
                dist[u][id] = nd;
                pq.push({-dist[u][id], u});
            }
        }
    }
    //se a distancia de N for infinita, significa q com esse tempo nn consigo checar
    //ent preciso aumentar, ent retorno false
    //cout << " " << dist[0][n-1] << endl;
    return dist[0][n-1] < INF;
}

signed main(){
    fastio;
    int m, k; cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    //dist e vertice
    vector<pair<int, int>> caras;
    for(int i = 0; i < k; i++){
        int a; cin >> a;
        a--;
        caras.push_back({0, a});
    }

    //montando o dijsktra pros k caras
    check(1, caras);
    caras.clear();

    int l = 0, r = 1e18, ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        //cout << mid << ": ";
        caras.push_back({mid, 0});
        if(check(0, caras)){
            r = mid-1;
            ans = mid;
        }
        else l = mid + 1;
        // for(int i = 0; i < n; i++){
        //     cout << dist[0][i] << " ";
        // }
        // cout << endl;
        caras.clear();
    }
    cout << ans << endl;
}