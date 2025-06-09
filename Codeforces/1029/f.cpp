#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;
const int MOD = 1e9+7;

vector<vector<int>> graph;
int a[MAX];
bool pos = true;
int bifurcacao = 0;

int power(int base, int exp) {
    int res = 1;
    base %= MOD; 
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int dfs(int v, int p, int d){
    if (graph[v].size() == 1 && graph[v][0] == p){
        a[v] = 2;
        return d;
    }
    vector<pair<int,int>> filhos;
    for (auto u : graph[v]){
        if (u == p) continue;
        filhos.push_back({dfs(u,v,d+1),u});
    }
    if(filhos.size() > 2) pos = false;
    if (filhos.size() == 1){
        a[v] = (a[filhos[0].second]*2)%MOD;
        return filhos[0].first;
    }
    else {
        bifurcacao++;
        int diff = abs(filhos[0].first - filhos[1].first);
        //cout << "DIFEE: "<< diff << endl;
        if (diff == 0) a[v] = 4;
        else a[v] = ((power(2,diff-1))%MOD * 6)%MOD;
        return max(filhos[0].first, filhos[1].first);
    }
}

void solve(){
    int n;
    cin >> n;
    graph.resize(n+1);
    pos = true;
    bifurcacao = 0;
    for (int i = 0; i <= n; i++){
        graph[i].clear();
        a[i] = 0;
    }
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1,1);
    if (!pos || bifurcacao > 1) cout << 0 << endl;
    else cout << a[1] << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}