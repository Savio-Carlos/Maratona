#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int B = 460;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> colors(n);
    for(int i = 0; i < n; i++) cin >> colors[i];

    vector<vector<pair<int,int>>> graph(n);
    for(int i = 1; i < n; i++){
        int u, v; ll c;
        cin >> u >> v >> c;
        --u; --v;
        graph[u].emplace_back(v, c);
        graph[v].emplace_back(u, c);
    }

    vector<int> heavy_id(n, -1);
    vector<int> hlist;
    for(int i = 0; i < n; i++){
        if((int)graph[i].size() > B){
            heavy_id[i] = hlist.size();
            hlist.push_back(i);
        }
    }
    int H = hlist.size();

    vector<unordered_map<int,ll>> somacor(H);
    vector<vector<pair<int,int>>> hne(H);
    
    for(int idx = 0; idx < H; idx++){
        int v = hlist[idx];
        somacor[idx].reserve(graph[v].size());
        for(auto &e: graph[v]){
            int u = e.first;
            ll c = e.second;
            somacor[idx][ colors[u] ] += c;
            if(heavy_id[u] != -1){
                hne[idx].emplace_back( heavy_id[u], c );
            }
        }
    }
    ll tot = 0;
    for(int u = 0; u < n; u++){
        for(auto &e: graph[u]){
            int v = e.first;
            ll c = e.second;
            if(u < v && colors[u] != colors[v]) tot += c;
        }
    }
    while(q--){
        int v, newc;
        cin >> v >> newc;
        --v;
        int oldc = colors[v];
        if(oldc == newc){
            cout << tot << '\n';
            continue;
        }

        ll delta = 0;
        int hid = heavy_id[v];
        if(hid == -1){
            for(auto &e: graph[v]){
                int u = e.first;
                ll c = e.second;
                bool was = (colors[u] != oldc);
                bool is_now = (colors[u] != newc);
                delta += (is_now - was) * c;
            }
        } else {
            delta = somacor[hid][oldc] - somacor[hid][newc];
        }
        tot += delta;
        colors[v] = newc;
        if(hid == -1){
            for(auto &e: graph[v]){
                int u = e.first;
                ll c = e.second;
                int uh = heavy_id[u];
                if(uh != -1){
                    somacor[uh][oldc] -= c;
                    somacor[uh][newc] += c;
                }
            }
        } else {
            for(auto &hc: hne[hid]){
                int uh = hc.first;
                ll c = hc.second;
                somacor[uh][oldc] -= c;
                somacor[uh][newc] += c;
            }
        }

        cout << tot << endl;
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}
