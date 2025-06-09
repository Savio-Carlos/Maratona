#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = LLONG_MAX;

vector<vector<pair<int,int>>> graph;
int n, visited[MAX];

bool djikstra(int mx){
    for (int i = 0; i < n; i++) visited[i] = 0;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        //if (dist[node] < d) continue;
        for (auto [u,w] : graph[node]){
            int nd = (w|mx);
            if (!visited[u] && nd == mx){
                visited[u] = 1;
                q.push(u);
            }
        } 
    }
    return visited[n-1];
}

signed main(){
    winton;
    int m;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[--a].push_back({--b,w});
        graph[b].push_back({a,w});
    }
    int l = 0, r = (1<<30)-1;
    int ans = 0;
    while(l < r){
        int mid = (l+(r-l)/2);
        if (djikstra(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << l << endl;
}   