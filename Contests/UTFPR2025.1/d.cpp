#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAXN = 1e6+7;
const int MAXC = 2e7+7;
const int INF = LLONG_MAX;
const int MOD = 998244353;

struct edge { 
    int to, nxt; 
};

int n, c, s, st[MAXN], prot[MAXN], used[MAXN], k[MAXN], forca[MAXN];
vector<edge> arestas;

signed main(){
    winton;
    cin >> n >> c >> s;
    for(int i = 1; i < n; i++) st[i] = -1;
    int cnt = 0;
    for(int i = 0; i < c; i++){
        int a, b;
        cin >> a >> b;
        edge x = {b, st[a]};
        arestas.push_back(x);
        st[a] = cnt++;

        edge y = {a, st[b]};
        arestas.push_back(y);
        st[b] = cnt++;
    }
    for(int i = 1; i <= s; i++){
        cin >> k[i] >> forca[i];
    }

    queue<int> q;
    for(int i = 1; i <= s; i++){
        int u = k[i];
        if (prot[u] != 0) {
            cout << "Nao" << endl;
            return 0;
        }
        prot[u] = i;
        used[u] = 0;
        q.push(u);
    }
    bool pos = true;
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        int id = prot[u];
        if(used[u] == forca[id]) continue;
        for(int j = st[u]; j != -1; j = arestas[j].nxt){
            int v = arestas[j].to;
            if(prot[v] == 0){
                prot[v] = id;
                used[v] = used[u] + 1;
                q.push(v);
            }
            else if(prot[v] != id) pos = false;
        }
    }
    for(int i = 1; i <= n; i++){
        if(prot[i] == 0) pos = false;
    }

    if (pos) cout << "Sim" << endl;
    else cout << "Nao" << endl;
}

