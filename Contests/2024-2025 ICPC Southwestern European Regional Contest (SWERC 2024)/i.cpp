#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int indeg[MAXN];

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            x--;
            graph[i].push_back(x);
            indeg[x]++;
        }
    }

    vector<int> dist(n+1, 0);
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++){
        if(!indeg[i]){
            dist[i] = -1;
            pq.push({1, i});
        }
    }

    int ans = 0;
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        ans = max(ans, d);
        for(auto u : graph[v]){
            if(--indeg[u] == 0){
                pq.push({d + 1, u});
            }
        }
    }

    if(ans == n) cout << 1 << endl;
    else cout << 0 << endl;
}