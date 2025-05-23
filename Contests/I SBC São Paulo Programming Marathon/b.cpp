#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int INF = 1e18;
const int MAXN = 1e5;
vector<pair<int, int>> graph[MAXN];
int dist[2][MAXN];
int n;
//fazer uma funcao check q calcula o dijkstra 

//v eh se eh o carlinhos ou nn
//preciso enviar os caras com a distancia 0 se for k e -mid se for o carlinhos
int check(int c, vector<pair<int, int>> caras){
    fill(dist[c], dist[c] + n, INF);

    //dist, v
    priority_queue<pair<int, int>> pq;
    for(auto u : caras){
        dist[c][u.second] = (c == 1 ? u.first : -u.first);
        pq.push({-dist[c][u.second], u.second});
    }

    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        //cout << d << " " << v << endl;
        if(dist[c][v] != d) continue;
        for(auto p : graph[v]){
            int u = p.first;
            int w = p.second;
            int nd = d + (c == 1? 2*w : w);
            if(nd < dist[c][u]){
                if(!c && nd > dist[1][u]) continue;
                dist[c][u] = nd;
                pq.push({-nd, u});           
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