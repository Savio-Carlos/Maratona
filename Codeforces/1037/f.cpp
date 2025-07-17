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
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;
const int B = 460;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> colors(n);
    for(int i = 0; i < n; i++) cin >> colors[i];

    vector<vector<pair<int,int>>> graph(n);
    for(int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
        graph[b].push_back({a,c});
    }

    vector<bool> h(n,false), hNbr(n,false);
    vector<int> hlist;
    for(int i = 0; i < n; i++) {
        if(graph[i].size() > B){
            h[i] = true;
            hlist.push_back(i);
        }
    }

    vector<unordered_map<int,int>> somacor(n);
    vector<vector<pair<int,int>>> hne(n);
    for(int v: hlist){
        for(auto [u,c]: graph[v]){
            somacor[v][ colors[u] ] += c;
            if(h[u]) hne[v].push_back({u,c});
        }
    }

    int tot = 0;
    for(int i = 0; i < n; i++){
        for(auto [v,c]: graph[i]){
            if(i < v && colors[i] != colors[v]) tot += c;
        }
    }
    while(q--){
        int v, cor;
        cin >> v >> cor;
        v--;
        int old = colors[v];
        if(old == cor){
            cout << tot << endl;
            continue;
        }
        int delta = 0;
        if(!h[v]){
            for(auto [u,c]: graph[v]){
                bool change = (colors[u] != old);
                bool now = (colors[u] != cor);
                delta += (now - change) * c;
            }
        } else {
            delta = somacor[v][old] - somacor[v][cor];
        }
        tot += delta;
        colors[v] = cor;
        if(!h[v]){
            for(auto [u,c]: graph[v]){
                if(h[u]){
                    somacor[u][old] -= c;
                    somacor[u][cor] += c;
                }
            }
        } else {
            for(auto [u,c]: hne[v]){
                somacor[u][old] -= c;
                somacor[u][cor] += c;
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