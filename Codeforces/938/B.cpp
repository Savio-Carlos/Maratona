#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, c, d;
        cin >> n >> c >> d;
        bool possible = true;
        vector<int> numbers(n*n), cor;
        int minimum = LLONG_MAX;
        int grid[n][n]; 
        for (int i = 0; i < n*n; i++){
            cin >> numbers[i];
            minimum = min(minimum, numbers[i]);
        }
        grid[0][0] =  minimum;
        for (int i = 0; i < n; i++){
            if (i > 0) grid[i][0] = grid[i-1][0] + d; 
            for (int j = 1; j < n; j++){
                grid[i][j] = grid[i][j-1] + c;
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cor.push_back(grid[i][j]);
            }
        }
        sort (numbers.begin(), numbers.end());
        sort (cor.begin(), cor.end());

        for (int i = 0; i < n*n; i++){
            if (cor[i] != numbers[i]) possible = false;
        }
        
        if (possible)cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
