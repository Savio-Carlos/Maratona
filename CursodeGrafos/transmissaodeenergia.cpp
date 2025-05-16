#include <bits/stdc++.h>
using namespace std;
#define ll long long

class grafo{
    public:
    int numVertices;
    vector<bool> visited;
    vector<vector<int>> matAdj;
    stack<int> ordem;
    
    grafo(int n) : numVertices(n), matAdj(n, vector<int>()), visited(n, false) {}

    void addAresta(int a, int b){
        matAdj[a].push_back(b);
        matAdj[b].push_back(a);        

    }

    void dfs(int v){
        visited[v] = true;
        for(auto u : matAdj[v]){
            if(!visited[u]){
                dfs(u);
            }
        }
    }
};

int main(){
    int n, m, teste = 1;
   
    
    while(cin >> n >> m){
        if (n == 0 && m == 0) break;
         grafo G(n);
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            G.addAresta(a,b);
        }
        G.dfs(0);
        int ans = 1;
        for (int i = 0; i < n; i++){
            //cout << G.visited[i] << " ";
            if (G.visited[i] == 0){
                ans = 0;
            }    
        }
        cout << "Teste " << teste << endl;
        if (ans) cout << "normal" << endl;
        else cout << "falha" << endl;
        cout << endl;
        teste++;
    }
}