#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 55;
const int MOD = 1e9+7;
char grid[MAXN][MAXN];

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid [i][j];
        }
    }
    for (int j = 0; j < m; j++){
        for (int i = n-1; i >= 0; i--){
            if (grid[i][j] == 'o'){
                int k = i;
                \
                while (k + 1 < n && grid[k+1][j] != '#' && grid[k+1][j] != 'o'){
                    k++;
                }
                grid[i][j] = '.';
                grid[k][j] = 'o';
            } 
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<< grid [i][j];
        }
        cout << endl;
    }
}