#include <bits/stdc++.h>
using namespace std;

#define int long long
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAX = 2e5+7;
vector<int> graph[MAX];
int ancestor[MAX];
bool visited[MAX];
int st = -1, en = -1;

bool dfs(int v, int p) {
    visited[v] = 1;
    ancestor[v] = p;
    for (int u : graph[v]) {
        if (u == p) continue;
        if (visited[u]) {
            st = u;
            en = v;
            return true;
        }
        if (dfs(u, v)) return true;
    }
    return false;
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(ancestor, -1, sizeof(ancestor));

    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            if(dfs(i, -1)){
                vector<int> cycle;
                int cur = en;
                while(cur != st){
                    cycle.push_back(cur);
                    cur = ancestor[cur];
                }
                cycle.push_back(st);
                cycle.push_back(en);
                
                cout << cycle.size() << endl;
                for(auto u : cycle) cout << u << " ";
                cout << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}