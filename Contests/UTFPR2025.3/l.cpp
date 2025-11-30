#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

signed main(){
    fastio;
    int n; cin >> n;
    int x = -1, y = -1;
    char grid[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '#' && x == -1) x = i;
        }
    }

    for(int i = 0; i < n; i++) if(grid[x][i] == '#') y = i;
    cout << "("  << x+1 << ", " << y+1 << ")\n";
}