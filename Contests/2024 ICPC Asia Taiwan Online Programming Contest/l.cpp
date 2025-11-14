#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int indeg[MAXN];

signed main(){
    fastio;
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }

    priority_queue<int> pq;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) pq.push(-i);
    }

    int cnt = 0; 
    vector<int> ans;
    while(!pq.empty()){
        auto v = pq.top(); pq.pop();
        v = -v;
        cnt++;
        ans.push_back(v);
        for(auto u : graph[v]){
            if((--indeg[u]) == 0) pq.push(-u);
        }
    }

    if(cnt == n){
        for(auto u : ans) cout << u << " ";
        cout << endl;
    }else cout << "IMPOSSIBLE\n";
}