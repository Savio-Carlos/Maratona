#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

void solve(){
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    int mx = 0;
    vector<pair<int,int>>pos;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if (grid[i][j] == mx) pos.push_back({i,j});
            if (grid[i][j] > mx){
                mx = grid[i][j];
                pos.clear();
                pos.push_back({i,j});
            }
        }
    }
    pair<int,int> m1 = pos[0]; 
    int c = -1;
    bool ans = true;
    for(auto [u, v] : pos){
        if(u == m1.first) continue;
        if(c == -1) c = v;
        else if(c != v){
            ans = false;
            break;
        }
    }
    if(ans){
        cout << mx-1 << endl;
        return;
    }
    int l = -1;
    ans = 1;
    for(auto [u, v] : pos){
        if(v == m1.second) continue;
        if(l == -1) l = u;
        else if(l != u){
            ans = false;
            break;
        }
    }
    if (ans) cout << mx-1 << endl;
    else cout << mx << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}
