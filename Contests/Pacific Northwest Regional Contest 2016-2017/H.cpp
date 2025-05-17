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

int n, m;
int visited[MAXN][MAXN];
vector<pair<int,int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

void floodfill(vector<string>& grid, int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
        while(!q.empty()){
            pair<int,int> atual = q.front();
            q.pop();
            for (const auto& move : moves) {
                int novox = atual.first + move.first;
                int novoy = atual.second + move.second;
                if (valid(novox,novoy) && !visited[novox][novoy] && grid[novox][novoy] != 'W'){
                    visited[novox][novoy] = 1;
                    q.push({novox,novoy});
                }
            }
    }
}


signed main(){
    winton;
    cin >> n >> m;
    vector<string> grid(n);

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'L' && !visited[i][j]) {
                floodfill(grid, i, j);
                ans++;
            }
            
        }
    }
    cout << ans << endl;
}