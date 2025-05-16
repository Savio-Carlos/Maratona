#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 50010;

vector<int> grauEntrada(MAXN, 0);
vector<int> adj[MAXN];

vector<int> toposort(int n){
    vector<int> l;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++){
        if (grauEntrada[i] == 0){
            pq.push(i);
        } 
    }

    while(!pq.empty()){
        int v = pq.top();
        pq.pop();

        l.push_back(v);
        for (auto u : adj[v]){
            grauEntrada[u]--;

            if (grauEntrada[u] == 0){
                pq.push(u);
            } 
        }
    }
    return l;
}

int main() {
    int n, m; 
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        grauEntrada[b]++;
        adj[a].push_back(b);
    }
    
    vector<int> ordenacao = toposort(n);

    if (ordenacao.size()!=n) cout << "*" << endl;
    else for (int i = 0; i < n; i++) cout << ordenacao[i] << endl;
}