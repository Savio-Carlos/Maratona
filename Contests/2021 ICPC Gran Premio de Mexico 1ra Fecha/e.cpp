#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << ": " << x << endl;

const int INF = 1e9;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

map<int,char> dir;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &u : grid) cin >> u;
    vector<vector<int>> dist(n, vector<int>(m, INF));

    pair<int,int> st;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '#') grid[i][j] = 'W';
            if (grid[i][j] == 'E'){
                st = {i,j};
                dist[i][j] = 0;
            }
        }
    }

    auto check = [&](int x, int y) -> bool{
        return (x >= 0 && x < n && y >= 0 && y < m) && (grid[x][y] == '.');
    };

    auto check2 = [&](int x, int y) -> bool{
        return (x >= 0 && x < n && y >= 0 && y < m) && (dist[x][y] != INF);
    };


    queue<pair<int,int>> q;
    q.push(st);
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (check(nx,ny)){
                if (dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    int qq;
    cin >> qq;
    while(qq--){
        int x, y;
        cin >> x >> y;
        x--;y--;

        if (grid[x][y] != '.') cout << grid[x][y] << endl;
        else if (dist[x][y] == INF) cout << '?' << endl;
        else {
            vector<pair<int,char>> pos;
            for (int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (check2(nx,ny)){
                    pos.emplace_back(dist[nx][ny], d);
                }

            }
            sort(all(pos));
            cout << dir[pos[0].second] << endl;
        }
    }
}

signed main(){
    winton;
    int t = 1;
    dir[0] = 'L';
    dir[1] = 'D';
    dir[2] = 'R';
    dir[3] = 'U';
    // cin >> t;
    while(t--) solve();
}   