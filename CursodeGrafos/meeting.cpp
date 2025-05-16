#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;

//floyd warshal -> pegar todos o maximo de cada ponto e pegar o minimo entre esses

int main() {
    int n, m;cin >> n >> m;

    vector<vector<int>> graph(n, vector<int> (n));
    vector<vector<int>> distance(n,vector<int> (n, INF));

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) distance[i][j] = 0;
            else if (graph[i][j]) distance[i][j] = graph[i][j];
            else distance[i][j] = INF;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }

    
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << distance[i][j] << " ";   
        }
        cout << endl;
    }*/
    
    int ans = INF;

    for (int i = 0; i < n; i++) {
        int localmax = 0;
        for (int j = 0; j < n; j++) {
            localmax = max(distance[j][i],localmax);        
        }
        ans = min(ans, localmax);
    }
    cout << ans << endl;
}