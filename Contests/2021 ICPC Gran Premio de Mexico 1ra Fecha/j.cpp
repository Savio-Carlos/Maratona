#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << ": " << x << endl;

const int MAX = 1e5+7;
const int INF = 1e9;
const int MOD = 998244353;

vector<int> graph[MAX];
vector<int> dist(MAX, INF);
vector<int> parent(MAX);
int tot = 0;

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}
int modiv(int a, int b){
    return (((a % MOD )* (fastExpo(b, MOD-2) % MOD)) % MOD);
}


void dfs(int v){
    if (graph[v].size() == 0){
        dist[v] = 1;
        return;
    }
    for (auto u : graph[v]){
        dfs(u);
        dist[v] = min(dist[v], dist[u] + 1);
    }
}

void calc(int v){
    int mn = dist[parent[v]] + 1;
    mn = min(mn, dist[v]);
    for (auto u : graph[v]){
        mn = min(dist[u] + 1, mn);
    }
    dist[v] = mn;
    // debug(v);
    // debug(dist[v]);
    tot += dist[v];
    for (auto u : graph[v]) calc(u);
}

signed main(){
    winton;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        int p;
        cin >> p;
        parent[i] = p;
        graph[p].push_back(i);
    }
    dist[0] = INF;
    dfs(1);
    calc(1);
    // debug(tot);
    cout << modiv(tot, n) << endl;

}



//find closest leaf