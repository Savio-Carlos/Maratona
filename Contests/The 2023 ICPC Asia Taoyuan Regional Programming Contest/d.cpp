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
const int MAX = 100+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

signed main() {
    winton;
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n, m;
        char d1, d2;
        cin >> n >> m >> d1 >> d2;
        vector<vector<char>> grid(n, vector<char> (m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 'V'){
                    if (i+1 < n && grid[i+1][j] != 'V') grid[i+1][j] = max(grid[i+1][j], d1);
                    if (i-1 >= 0 && grid[i-1][j] != 'V') grid[i-1][j] = max(grid[i-1][j], d1);
                    if (j-1 >= 0 && grid[i][j-1] != 'V') grid[i][j-1] = max(grid[i][j-1], d1);
                    if (j+1 < m && grid[i][j+1] != 'V') grid[i][j+1] = max(grid[i][j+1], d1);

                    if ((i+1 < n && j+1 < m) && (grid[i+1][j+1] != 'V')) grid[i+1][j+1] = max(grid[i+1][j+1], d2);
                    if ((i-1 >= 0 && j+1 < m) && (grid[i-1][j+1] != 'V')) grid[i-1][j+1] = max(grid[i-1][j+1], d2);
                    if ((i+1 < n && j-1 >= 0) && (grid[i+1][j-1] != 'V')) grid[i+1][j-1] = max(grid[i+1][j-1], d2);
                    if ((i-1 >= 0 && j-1 >= 0) && (grid[i-1][j-1] != 'V')) grid[i-1][j-1] = max(grid[i-1][j-1], d2);

                }
            }
        }
        cout << "Airplane #" << tt << ":" << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '.') cout << "0";
                else cout << grid[i][j] << "";
            }
            cout << endl;
        }
    }
}
