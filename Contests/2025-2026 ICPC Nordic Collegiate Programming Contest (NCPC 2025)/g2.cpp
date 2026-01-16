#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAXN = 2e5+7;
vector<int> graph[MAXN], comp[MAXN];
int visited[MAXN];
int c =0;

void dfs(int v){
    comp[c].push_back(v);
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}

signed main(){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            c++;
        }
    }

    vector<int> ans(n, 0);
    for(int i = 0; i < c; i++){
        if(comp[i].size() < k){
            cout << "impossible\n";
            return 0;
        }
        int cnt = 1;
        for(auto u : comp[i]){
            if(cnt > k) ans[u] = 1;
            else ans[u] = cnt;
            cnt++;
        }
    }
    for(auto u : ans) cout << u << " ";
    cout << endl;
}