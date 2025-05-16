#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 110;

vector<pair<int, pair<int,int>>> rodovias, ferrovias;
int comp[10001];

void dsu(int n){
    for (int i = 1; i <= n; i++){
        comp[i] = i;
    }
}

int find(int u){
    if (comp[u] == u) return u;
    return comp[u] = find(comp[u]);
}

void Union(int u, int v){
    u = find(u);
    v = find(v);
    comp[v] = u; 
}

int mst(int n, int m, vector<pair<int, pair<int,int>>> &caminho){
    
    sort (caminho.begin(), caminho.end());
    int custo = 0;
    for (int i = 0; i < m; i++){
        int u, v, c;
        c = caminho[i].first;
        u = caminho[i].second.first;
        v = caminho[i].second.second; 
        if (find(u) != find(v)){
            Union(u,v);
            custo += c;
        }
    }
    return custo;
}

int main(){
    int n, f, r; 
    cin >> n >> f >> r;
    while(f--){
        int a, b, c;
        cin >> a >> b >> c;
   
        ferrovias.push_back({c,{b,a}});
    }
    while(r--){
        int a, b, c;
        cin >> a >> b >> c;
     
        rodovias.push_back({c,{b,a}});
    }
    dsu(n);
    int fcost = mst(n,ferrovias.size(),ferrovias);
    int rcost = mst(n,rodovias.size(),rodovias);
    
    cout << fcost + rcost << endl;


}