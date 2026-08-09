#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define ll long long

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

const int MAX = 1e5+7;
vector<pair<int,int>> graph[MAX];
int visited[MAX], best[MAX];
int ans = 0, k;

void dfs(int v){
    visited[v] = 1;
    for (auto [u,w] : graph[v]){
        if (visited[u]) continue;
        dfs(u);
    }
}

void dfs2(int v){
    best[v] = k;
    for (auto [u,w] : graph[v]){
        if (best[u] == k) continue;
        if ((w & ans) != ans) continue;
        if (((w >> k) & 1) == 0) continue;
        dfs2(u);
    }
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b>> c;
        graph[a].push_back({b,c}); 
    }

    dfs(1);
    if (!visited[n]){
        cout << -1 << endl;
        return 0;
    }
    memset(best, -1, sizeof(best));
    for (int i = 30; i >= 0; i--){
        k = i;
        dfs2(1);
        if (best[n] == i) ans |= (1<<i);
    }
    cout << ans << endl;
}
