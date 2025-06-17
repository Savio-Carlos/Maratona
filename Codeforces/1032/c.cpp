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
    bool ans = true;
    if (pos.size() > 2){
        pair<int,int> m1 = {pos[0].first,pos[1].second};
        pair<int,int> m2 = {pos[1].first,pos[0].second};
        pair<int,int> m3 = pos[1];
        pair<int,int> m4 = pos[0];
        //cout << m1.first << " " << m1.second << endl;
        //cout << m2.first << " " << m2.second << endl;
        bool flag1 = true, flag2 = true;
        bool flag3 = true, flag4 = true;
        for (auto [u,v] : pos){
            if (u != m1.first && v != m1.second) flag1 = false;
            if (u != m2.first && v != m2.second) flag2 = false;
            if (u != m3.first && v != m3.second) flag3 = false;
            if (u != m4.first && v != m4.second) flag4 = false;
        }
        //cout << flag1 << " " << flag2 << endl;
        if (flag1 == false && flag2 == false && flag3 == false && flag4 == false) ans = false;
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