#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;
const int MAXK = 65;
const int MAXL = 20;

int n, k, q;
vector<vector<int>> graph;
int ancestor[MAXN][MAXL+1], visited[MAXN], fruits[MAXN][MAXK+1], depth[MAXN];

void dfs(int v, int p){
    ancestor[v][0] = p;
    visited[v] = 1;
    for (int i = 1; i <= MAXL; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }

    for (auto u : graph[v]){
        if(!visited[u]){
            depth[u] = depth[v]+1;
            for (int i = 1; i <= k; i++){
                fruits[u][i] += fruits[v][i];
                // a dp aqui se resume a somar a quantidade de cada fruta do pai no filho
                // isso calcula a quantidade de frutas da raiz ate cada no 
            }
            dfs(u,v);
        }
    }
}

int lca(int v, int u){
    if (depth[v] < depth[u]) swap(u,v);

    for (int i = MAXL-1; i >= 0; i--){
        if ((depth[v] - (1<<i)) >= depth[u]){ 
            v = ancestor[v][i];
        }
    }

    if (u == v) return v;

    for (int i = MAXL-1; i >= 0; i--){
        if (ancestor[v][i] != ancestor[u][i]){
            v = ancestor[v][i];
            u = ancestor[u][i];
        }
    }
    return ancestor[v][0];
}



signed main () {
    winton;
    cin >> n >> k;
    graph.resize(n+1);
    for (int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    } 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            cin >> fruits[i][j];
        }   
    }
    
    ancestor[1][0] = 1;
    depth[1] = 1;
    dfs(1,1);

    int q;
    cin >> q;
    int diff[70];
    while(q--){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        int mac = lca(a,b);
        for (int i = 1; i <= k; i++){
            if (mac == 1) diff[i] = fruits[a][i] + fruits[b][i] - fruits[1][i];
            /* Nesse caso, somamos a quantidade de frutas de 1 ate a e de 1 ate b, 
                depois diminuimos a quantidade de frutas em 1 ja que contamos duas vezes*/
            else diff[i] = fruits[a][i] + fruits[b][i] - fruits[ancestor[mac][0]][i] - fruits[mac][i];
            /* Nesse caso, somamos a quantidade de frutas de 1 ate a e de 1 ate b, mas como nunca passamos por 1,
            entao diminuimos a quantidade de frutas no lca e do pai dele
            do lca por que ele foi contado duas vezes(nosso nova raiz basicamente)
            do pai dele por que queremos tirar todo mundo pra cima do lca ja que nao passamos por la, e o pai do lca
            tem toda essa quantidade acumulada 
            */
            if (diff[i]%2 == 1) ans++;
        }
        cout << ans << endl;
    }

}