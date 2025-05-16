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

    void addAresta(int n, int m, int d){
        matAdj[n].push_back(m);
        matAdjReversa[m].push_back(n);
        if (d==2){
            matAdj[m].push_back(n);
            matAdjReversa[n].push_back(m);
        }
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

        for (int i = 0; i < numVertices; i++) {
            visitados[i] = false;
        }

        int componente_conexo = 0;
        while(!ordem.empty()){
            int v = ordem.top();
            ordem.pop();
            if (!visitados[v]) {
                dfs2(v);
                componente_conexo++;
            }
        }
        return (componente_conexo == 1);
    }
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        grafo G(n);

        for (int i = 0; i < m; ++i) {
            int v, W, P;
            cin >> v >> W >> P;
            v--; W--;
            G.addAresta(v, W, P);
        }
        int ans = G.solve();
        if (ans == 1) cout << "1" << endl;
        else cout << "0" << endl;
    }
}