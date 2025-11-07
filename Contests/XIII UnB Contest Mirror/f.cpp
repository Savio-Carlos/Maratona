#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAXN = 101; 
vector<int> graph[MAXN];
int visited[MAXN];
int x = 0, found = 0;

int dfs(int v, int p, int cnt){
    cout << v+1 << " " << p+1 << " " << cnt << endl;
    visited[v] = 1;
    int ans = 0;
    for(auto u : graph[v]){
        if(u == p) continue;
        //posso querer ignorar uma edge
        if(u == x){
            found = 1;
        }
        if(!visited[u]){
            ans = max(dfs(u, v, cnt+1), ans);
        }
    }
    if(found){
        ans = max(ans, cnt);
    }
    return ans;
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int res = 0;
    for(auto u : graph[1]){
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        found = 0;
        //int v = dfs(u, 1, 0)+1;
        //cout <<"filho:" <<  u+1 << " valor: " << v << endl;
        res = max(dfs(u, 2, 0), res);
        cout << res << endl;
    }

    // int ans = 0;
    // for(int i = 0; i < n; i++){
    //     int res = 0;
    //     x = i;
    //     cout << "pai " << i+1 << endl;
    //     for(auto u : graph[i]){
    //         found = 0;
    //         for(int j = 0; j < n; j++){
    //             visited[j] = 0;
    //         }
    //         visited[i] = 1;
    //         int v = dfs(u, i, 0);
    //         cout << "resultado da dfs: " << v << endl;
    //         res = max(dfs(u, i, 0), res);

    //         cout << endl;
    //     }
    //     cout << endl;
    //     //cout << res << " " << i << endl << endl;
    //     ans += (i+1)*(res);
    // }
   // cout << ans << endl;
}