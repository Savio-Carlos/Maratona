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
int artcnt = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && (grid[x][y] == 'Q' || grid[x][y] == 'H');
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
            bool art = false;
            if (px == -1 && py == -1) {
                if (c >= 2) art = true;
            } 
            else if (low[nx][ny] >= tin[x][y]) art = true;
            if (art) artcnt++;
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

    int queijos = 0;
    pair<int,int> st;
    for (int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if (grid[i][j] == 'Q') queijos++;
            if (grid[i][j] == 'H') st = {i, j};
        }
    }

    auto [sx, sy] = st;
    int r = 0;
    for (int i = 0; i < 4; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 'Q') r++;
    }

    dfs(sx, sy, -1, -1);

    int ans = min(artcnt, r);
    if (ans == queijos) cout << -1 << endl;
    else cout << ans << endl;
}