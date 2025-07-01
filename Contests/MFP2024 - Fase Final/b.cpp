#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 3e5+7;
const int INF = LLONG_MAX;

int n, k, cuts = 0, a[MAX], sub[MAX];
vector<vector<int>> graph;
vector<pair<int,int>> ans;

void dfs(int v, int p, int mid){
    sub[v] = a[v];
    for (auto u : graph[v]){
        if (u == p) continue;
        dfs(u,v,mid);
        if (sub[u]+sub[v] > mid){
            cuts++;
            ans.push_back({v,u});
        }
        else sub[v] += sub[u];
    }
   // debug (sub[v]);
}

signed main(){
    winton;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    graph.resize(n);
    for (int i = 1; i < n; i++){
        int fr, to;
        cin >> fr >> to;
        graph[--fr].push_back(--to);
        graph[to].push_back(fr);
    }
    int l = 0, r = sum;
    vector<pair<int,int>> res;
    while(l < r){
        cuts = 0;
        ans.clear();
        for (int i = 0; i < n; i++){
            sub[i] = 0;
        }
        int mid = l + (r-l)/2;
        //debug(mid);
        dfs(0,-1, mid);
        if(cuts <= k){
            r = mid;
            res = ans;
        }
        else {
            l = mid+1;
        }
    }
    cout << res.size() << endl;
    for (auto &[u,v] : res) cout << u+1 << " " << v+1 << endl;
}