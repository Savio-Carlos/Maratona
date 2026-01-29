
#include <bits/stdc++.h>
using namespace std;
 
#define fastio2 ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define ld long double
#define dbg(x) cout << x << " "; 
#define endl '\n'

signed main(){
    fastio2;
   int n, m;
   vector<vector<ld>> probs(n+1, vector<ld>(n+1));
   for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> probs[i][j];
        }
    }
    vector<ld> cur (n+1, 0.0);
    cur[1] = 1.0;

    for (int i = 0; i < m; i++){
        
    }
}