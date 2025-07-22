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
const int MAX = 1e3+7;
const int MOD = 1e9+7;
const ld LINF = 1e18;

vector<vector<pair<int,int>>> graph;
int n, t, rewards[MAX];
ld ganho[MAX][MAX];

signed main() {
    winton;
    cin >> n >> t;
    graph.resize(n);
    for (int i = 0; i < n; i++){
        cin >> rewards[i];
    }
    for (int i = 0; i < n; i++){
        int e;
        cin >> e;
        while (e--){
            int s;
            ld p;
            cin >> s >> p;
            graph[i].push_back({s,p});
        }
    }

    for (int i = 0; i < n; i++){
        ganho[i][0] = rewards[i];
    }
    for (int i = 1; i <= t; i++){
        for (int v = 0; v < n; v++){
            ganho[v][i] += rewards[v];
            for (auto [u,p] : graph[v]){
                ganho[v][i] += ganho[u][i-1]*p/100;
            }
        }
    }
    //isso vai dar TLE mas eu quero testar
    ld ans = ganho[0][t];
    cout << fixed << setprecision(6) << ans << endl;
}

