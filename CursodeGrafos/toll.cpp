#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;

class grafo{
    public:
    int numVertices;
    vector<vector<int>> matAdj;
    vector<int> d;

    grafo(int n) : numVertices(n), matAdj(n, vector<int>()), d(n,INF) {}

    void addAresta(int n, int m){
        matAdj[n].push_back(m);
        matAdj[m].push_back(n);
    }

    void diskra(int s){
        queue<int> q;
        q.push(s);
        d[s] = 0;

        while(!q.empty()){
            int atual = q.front();
            q.pop();

            for (int i : matAdj[atual]){
                if (d[atual] + 1 < d[i]){
                    d[i] = d[atual] + 1;
                    q.push(i);
                }
            
            }
        }
    }
};

int main() {
    int c, e, l, p, t = 1;
    while (cin >> c >> e >> l >> p){
        if (c == 0) break;
        grafo G(c);
        for (int i = 0; i < e; i++){
            int a, b; cin >> a >> b;
            a--; b--;
            G.addAresta(a,b);
        }
        G.diskra(l-1);

        cout << "Teste " << t << endl;
        for (int i = 0; i < c; i++){
            if (G.d[i] <= p && i != l-1) cout << i+1 << " ";
        }
        cout << endl << endl;
        t++;
    }

}