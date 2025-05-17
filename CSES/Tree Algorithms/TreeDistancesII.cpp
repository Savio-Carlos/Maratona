#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;


int ans[MAX], distsum[MAX], sz[MAX];
vector<int> graph[MAX];

void dfs(int v, int p){
    sz[v] = 1;
    distsum[v] = 0;
    for(int u : graph[v]){ 
        if(u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
        distsum[v] += distsum[u] + sz[u];  
    }
}

void dfs2(int v, int p){
    //cout << "v: " << v+1 << " distsum[v]: " << distsum[v] << " size: " << size << " acc: " << acc << endl; 
    for(int u : graph[v]){ 
        if(u == p) continue;
        ans[u] = ans[v] - 2*sz[u] + sz[0];
        dfs2(u,v);
    }
}


signed main(){
    winton;
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    // for (int i = 0; i < n; i++){
    //     cout << distsum[i] << " ";
    // }cout << endl;
    ans[0] = distsum[0];
    dfs2(0,-1);
        for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

}