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
    //cout << dist[n-1][0] << endl;
    if(dist[n-1][0] == INF) return false;
    return true;
}

signed main(){
    winton;
    int m, k;
    cin >> n >> m >> k;
    graph.resize(n);
    for (int i = 0; i < MAX; i++){
        dist[i][1] = dist[i][0] = INF;
    }
    for (int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
        graph[b].push_back({a,c});
    }
    vector<pair<int,int>> st;
    for (int i = 0; i < k; i++){
        int x;
        cin >> x;
        st.push_back({0,x-1});
    }
    djikstraK(st, 1);
    int l = 0, r = 1e18;
    int ans = 0;
    while (l <= r){
        for (int i = 0; i < MAX; i++){
            dist[i][0] = INF;
        }
        dist[0][0] = 0;
        int mid = (l+(r-l)/2);
        vector<pair<int,int>> cur = {{-mid,0}};
        if (djikstraK(cur,0)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
        // cout << "dist 0: " << "MID = " << mid << endl;
        // for (int i = 0; i < n; i++){
        //     cout << dist[i][0] << " ";
        // }
        // cout << endl;
    }
    // cout << "dist 1:" << endl;
    //     for (int i = 0; i < n; i++){
    //     cout << dist[i][1] << " ";
    // }
    //cout << endl;
    cout << max(ans, 0LL) << endl;
}