//Toposort
//
// Fazer dfs pra pegar o indeg se necessario
int indeg[MAX];

vector<int> order;
queue<int> q;

for (int i = 0; i < MAX; i++){
    if (indeg[i] == 0)q.push(i);
}
while(!q.empty()){
    int cur = q.front();   
    order.push_back(cur);
    q.pop();
    for (auto u : graph[cur]){
        indeg[u]--;
        if (indeg[u] == 0)q.push(u);
    }
}
