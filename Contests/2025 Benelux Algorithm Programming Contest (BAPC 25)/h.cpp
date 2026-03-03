#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int visited[MAXN], dist[MAXN];

vector<int> ans;

void func(int x, int nx){
    stack<pair<int, int>> q;
    q.push({x, x});
    while(!q.empty()){
        auto [v, p] = q.top(); q.pop();
        ans.push_back(v);
        if(v == 1) break;
        for(auto u : graph[v]){
            if(u == p) continue;
            if(u == nx) continue;
            if(dist[u] == dist[v]-1){
                q.push({u, v});
            }
        }
    }

    reverse(ans.begin(), ans.end());
    // for(auto u : ans){
    //     cout << u << " ";
    // }
    // cout << endl;
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<pair<int, int>> q;
    q.push({1, 1});
    for(int i = 1; i <= n; i++) dist[i] = -1;
    dist[1] = 1;
    int a = -1, b = -1, best = INT_MAX;
    while(!q.empty()){
        auto [v, p] = q.front(); q.pop();
        //cout << v << " " << p << endl;
        for(auto u : graph[v]){
            //cout << u << endl;
            if(u == p) continue;
            //cout << u << " " << dist[u] << endl;
            if(dist[u] == -1){
                dist[u] = dist[v]+1;
                q.push({u, v});
            }else{
                if(dist[u] + dist[v] < best){
                    best = dist[u] + dist[v];
                    a = u;
                    b = v;
                }
            }
        }
    }  
    if(best >= INT_MAX){
        cout << "impossible\n";
        return 0;
    }
    //cout << best << endl;
    func(a, b);
    func(b, a);
    cout << (int)ans.size() << endl;
    for(auto u : ans){
        cout << u << " "; 
    }
    cout << endl;

}