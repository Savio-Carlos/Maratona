#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

int n, k;
vector<vector<int>> graph;
vector<int> visited;

multiset<int> dfs(int v){
    visited[v] = 1;
    multiset<int> cur;
    for(auto u : graph[v]){
        if(!visited[u]){
            multiset<int> filho = dfs(u);
            if(filho.size() > cur.size()) swap(filho, cur);
            cur.insert(filho.begin(), filho.end());
        }
    }

    if(cur.empty()){
        cur.insert(1);
    }else{
        auto it = cur.end();
        int x = *(--it);
        x++;
        cur.erase(it);
        cur.insert(x);
    }
    return cur;
}

signed main(){
    fastio;
    cin >> n >> k;
    graph.resize(n);
    visited.resize(n);
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        graph[i ].push_back(--x);
        graph[x].push_back(i);
        visited[i] = 0;
    }
    int ans = 0;
    multiset<int> ms = dfs(0);
    auto it = ms.end();
    it--;
    for (int i = 0; i < k; i++){
        ans += *it;
        it--;
    }
    cout << ans << endl;
}

