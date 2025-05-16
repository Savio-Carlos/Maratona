#include <bits/stdc++.h>
using namespace std;
#define ll long long

class grafo{
    public:
    int numVertices;
    vector<vector<int>> matAdj;
    set<int> subs;

    grafo(int n) : numVertices(n), matAdj(n, vector<int>()) {}

    void addAresta(int a, int b){
        matAdj[a].push_back(b);
        matAdj[b].push_back(a);        
    }

    void bfs(int removido){
        vector<bool> visitados(numVertices, false);
        queue<int> q;
        int start = -1;
        for (int i = 0; i < numVertices; i++) {
            if (i != removido) {
                start = i;
                break;
            }
        }
        if (start == -1) return;
        q.push(start);
        visitados[start] = true;

        while(!q.empty()){
            int n = q.size();
            int atual = q.front();
            q.pop();
            if (atual == removido) continue;
                
            for (auto u : matAdj[atual]){
                if(!visitados[u] && u != removido){
                    q.push(u);
                    visitados[u] = true;
                }
            }
            
        }
        int cnt = 0;
        for (int i = 0; i < numVertices; i++){
            if(visitados[i]) cnt++;
        }
        if (cnt!=numVertices-1) subs.insert(removido+1);
    }
};

int main() {
    int N, M, i = 1;
    while(cin >> N >> M){
        if (N == 0 && M == 0) break;
        grafo G(N);

        for (int i = 0; i < M; i++){
            int a, b;
            cin >> a >> b;
            G.addAresta(a-1,b-1);
        }

        for (int i = 0; i < N; i++){
            G.bfs(i);
        }

        cout << "Teste " << i++ << endl;
        if (G.subs.empty()) cout << "nenhum";
        for (auto u : G.subs){
            cout << u << " ";
        }
        cout << endl << endl;
        G.subs.clear();
    }
    cout << endl;
}