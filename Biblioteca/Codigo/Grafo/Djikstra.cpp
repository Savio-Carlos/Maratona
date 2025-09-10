//Djikstra

int dist[MAX]
void djikstra(int st){
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < n; i++)dist[i]=LLONG_MAX;
    dist[st] = 0;
    pq.push({0,st});
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
}