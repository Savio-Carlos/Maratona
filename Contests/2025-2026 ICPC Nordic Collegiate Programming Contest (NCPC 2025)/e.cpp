#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n;
    cin >> n;
    int m = 2 * n - 1;
    int cnt = 0;
    vector<vector<char>> grid(n, vector<char> (m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'C') cnt++;
        }
    }

    if (cnt%2 == 1){
        cout << "impossible" << endl;
        return 0;
    }
    auto ans = grid;
    int first = 0;

    for (int i = 0; i < m; i++)if (grid[n-1][i] == 'C') first++; 

    if (first <= cnt/2){
        int goal = 0;
        for (int i = 0; i < m; i++) if (grid[n-1][i] == '#') continue; grid[n-1][i] = 'A'; 
        goal += first;

        for (int i = 0; i < n; i++){
            queue<int> q;
            q.push(i);
            q.push(m-i);
            while (!q.empty()){
                auto v = q.front(); q.pop();
                
            }
        }
    }   

}