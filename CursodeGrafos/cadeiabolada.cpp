#include <bits/stdc++.h>
using namespace std;
#define ll long long

class grafo{
    public:
    int numVertices;
    vector<bool> visitados;
    vector<vector<int>> matAdj;
    vector<vector<int>> matAdjReversa;
    stack<int> ordem;
    
    grafo(int n) : numVertices(n), matAdj(n, vector<int>()), matAdjReversa(n, vector<int>()), visitados(n, false) {}

    void addAresta(int n, int m){
        matAdj[n].push_back(m);
        matAdjReversa[m].push_back(n);
    }

    void dfs1(int v){
        visitados[v] = true;
        for(auto i : matAdj[v]){
            if (!visitados[i]){
                dfs1(i);
            }
        }
        ordem.push(v);
    }

    void dfs2(int v){
        visitados[v] = true;
        for(auto i : matAdjReversa[v]){
            if (!visitados[i]){
                dfs2(i);
            }
        }
    }

    bool solve() {
        for (int i = 0; i < numVertices; i++) {
            if (!visitados[i]) {
                dfs1(i);
            }
        }

        fill(visitados.begin(), visitados.end(), false);

        int componente_conexo = 0;
        while(!ordem.empty()){
            int v = ordem.top();
            ordem.pop();
            if (!visitados[v]) {
                dfs2(v);
                componente_conexo++;
            }
        }
        return (componente_conexo==1);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    grafo G(n);

    for (int i = 0; i < m; ++i) {
        int v, W;
         cin >> v >> W;
        v--; W--;
        G.addAresta(v, W);
    }
        int ans = G.solve();
        if (ans) cout << "Bolada" << endl;
        else cout << "Nao Bolada" << endl;
    
}