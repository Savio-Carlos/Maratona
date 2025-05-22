#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 1e5+7;

vector<vector<int>> graph;
int n, k, temp[MAX], mx, ans = 0;

bool dfs(int v, int p,int depth){
    bool pegou = false;
    if (temp[v] >  k) {
        pegou = true;             
    }
    for(auto u : graph[v]){
        if (u == p) continue;
        if (dfs(u,v ,depth+1)){
            ans += 2;
            pegou = true;
        }
    }
    return pegou;
}

signed main(){
    winton;
    cin >> n >> k;
    graph.resize(n);
    for (int i = 0; i < n; i++){
        cin >> temp[i];
    }
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1, 0);
    cout << ans - mx << endl;
}
