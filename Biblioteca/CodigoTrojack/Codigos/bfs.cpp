// BFS
// O(V + E)

void bfs_iterativa(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int viz : graph[node]) {
            if (!visited[viz]) {
                visited[viz] = true;
                q.push(viz);
            }
        }
    }
}

void bfs_recursiva(vector<int> nivel) {
    if (nivel.empty()) return;

    vector<int> proximo_nivel;
    for (int node : nivel) {
        cout << node << " ";
        for (int viz : graph[node]) {
            if (!visited[viz]) {
                visited[viz] = true;
                proximo_nivel.push_back(viz);
            }
        }
    }

    bfs_recursiva(proximo_nivel); 
}