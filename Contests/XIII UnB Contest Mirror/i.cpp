#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n, m;
    cin >> m >> n;
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if (isupper(grid[i][j])) grid[i][j] = tolower(grid[i][j]) ;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'v'){//so pensar a partir do meio
                //check vertical
                if (i-1 >= 0 && i+1 < n){
                    if (grid[i-1][j] == 'u' && grid[i+1][j] == 'a') ans++; 
                    if (grid[i-1][j] == 'a' && grid[i+1][j] == 'u') ans++; 
                }

                //check horizontal
                if (j-1 >= 0 && j+1 < m){
                    if (grid[i][j-1] == 'u' && grid[i][j+1] == 'a') ans++; 
                    if (grid[i][j-1] == 'a' && grid[i][j+1] == 'u') ans++; 
                }

                //check diagonal 
                if (i-1 >= 0 && i+1 < n && j-1 >= 0 && j+1 < m){
                    if (grid[i-1][j-1] == 'u' && grid[i+1][j+1] == 'a') ans++; 
                    if (grid[i-1][j-1] == 'a' && grid[i+1][j+1] == 'u') ans++; 
                    if (grid[i+1][j-1] == 'u' && grid[i-1][j+1] == 'a') ans++; 
                    if (grid[i+1][j-1] == 'a' && grid[i-1][j+1] == 'u') ans++;
                }

            }
        }
    }
    cout << ans << endl;
}