#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e17;
const int MAXN=2e5+7;
vector<pair<int, int>> graph[MAXN];

int n, k, mid, cnt = 0; 

int dfs(int v, int p){
    int dist = 0;
    vector<int> filho;
    for(auto [u, l] : graph[v]){
        if(u == p) continue;
        if(l > mid){
            return -INF;
        }
        int d = dfs(u, v);
        if(d == -INF) return d;
        //adicionando no filho
        if(l + d > mid){
            cnt++;
            filho.push_back(l);
        }
        else filho.push_back(l+d);
    }

    sort(filho.rbegin(), filho.rend());
    
    for(int i = 0, c = 0; i < filho.size() && c < 2; i++, c++) dist += filho[i];
    if(dist > mid){
        cnt++;
        dist = 0;
    }
    else if (!filho.empty()) dist = filho[0];
    return dist; 
}

bool check(){
    int v = dfs(0, -1);
    if(v <= -INF) return false;
    if(v > mid) cnt++;
    return cnt <= k;
}

void solve(){
    cin >> n >> k;
    int mn = INF, mx = 0;
    for(int i = 0; i < n-1; i++){
        int a, b, l; cin >> a >> b >> l;
        a--, b--;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
        mx += l;
        mn = min(l, mn);
    }

    int l = mn, r = mx, ans = mx;
    while(l <= r){
        mid = l + (r-l)/2;
        //cout << mid << " " << res << endl;
        cnt = 0;
        if(check()){
            ans = mid;
            r = mid-1;
        } 
        else l = mid+1;
    }
    cout << ans << endl;
}

signed main() {
    fastio;
    int t; 
    t = 1;
    while(t--){
        solve();
    }
}
