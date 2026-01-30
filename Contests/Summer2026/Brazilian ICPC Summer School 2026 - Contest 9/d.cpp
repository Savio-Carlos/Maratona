#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cout << x << " "; 
#define endl '\n'

int n, m;
vector<string> grid;
int t = 0;
vector<vector<int>> tin, low;
vector<vector<bool>> visited;
bool art = false;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '#';
}

void dfs(int x, int y, int px, int py) {
    visited[x][y] = true;
    tin[x][y] = low[x][y] = t++;
    int c = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!valid(nx, ny)) continue;
        if (nx == px && ny == py) continue;
        
        if (visited[nx][ny]) low[x][y] = min(low[x][y], tin[nx][ny]);
        else {
            c++;
            dfs(nx, ny, x, y);
            low[x][y] = min(low[x][y], low[nx][ny]);
            if (px == -1 && py == -1) {
                if (c >= 2) art = true;
            } 
            else if (low[nx][ny] >= tin[x][y]) art = true;
        }
    }
}

signed main(){
    fastio;
    cin >> n >> m;
    grid.resize(n);
    tin.assign(n, vector<int>(m, 0));
    low.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));
    
    int cnt = 0;
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                cnt++;
                sx = i; sy = j;
            }
        }
    }
    
    if (cnt <= 2) {
        cout << -1 << endl;
        return 0;
    }
    dfs(sx, sy, -1, -1);
    if (art) cout << 1 << endl;
    else cout << 2 << endl;
}
