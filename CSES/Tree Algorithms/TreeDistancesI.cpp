#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;

int ans[MAX], maxdist[MAX];
vector<vector<int>> graph;

void dfs1(int v, int p){
    for(auto u : graph[v]){ 
        if(u==p)continue;
        dfs1(u,v);
        maxdist[v] = max(maxdist[v],maxdist[u]+1);   
    }
}

void dfs2(int v, int p, int dist){
    ans[v] = max(maxdist[v], dist);
    int max1 = 0, max2 = 0;
    for(auto u : graph[v]){
        if(u==p)continue;
        if (maxdist[u]+1 > max1){
            max2 = max1;
            max1 = maxdist[u]+1;
        }
        else if (maxdist[u]+1 > max2){
            max2 = maxdist[u]+1;
        }
    }
    for(auto u : graph[v]){
        if(u==p)continue;
        if (maxdist[u]+1 == max1) dfs2(u,v,max(max2,dist)+1);
        else dfs2(u,v,max(max1,dist)+1);
    }

}

signed main(){
    winton;
    int n;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs1(0,-1);
    dfs2(0,-1,0);
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}