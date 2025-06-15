#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 505;
const int INF = INT_MAX;

char grid[MAX][MAX];

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++){
            if (grid[i][j] == '#') continue;
            if (grid[i][j] == '.'){
                if (i > 0 && grid[i-1][j] == 'o') grid[i][j] = 'o';
            }
            if (grid[i][j] == 'o'){
                if (i < n+1 && grid[i+1][j] == '#'){
                    if (grid[i][j+1] != '#' && j < m-1)grid[i][j+1] = 'o';
                    if (grid[i][j-1] != '#' && j > 0)grid[i][j-1] = 'o';
                }
            }
        }
        for (int j = m-1; j >= 0; j--){
            if (grid[i][j] == '#') continue;
            if (grid[i][j] == 'o'){
                if (i >= 0 && grid[i+1][j] == '#'){
                    if (grid[i][j+1] != '#' && j < m-1)grid[i][j+1] = 'o';
                    if (grid[i][j-1] != '#' && j > 0)grid[i][j-1] = 'o';
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}
