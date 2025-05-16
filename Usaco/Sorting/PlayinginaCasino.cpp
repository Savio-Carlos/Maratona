#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(m, vector<int>(n));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[j][i];
            }
        }
        for (int j = 0; j < m; j++)sort(all(grid[j]));

        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans += (2*j + 1 - n) * grid[i][j];
            }
        }

        cout << ans << endl;
    }
}