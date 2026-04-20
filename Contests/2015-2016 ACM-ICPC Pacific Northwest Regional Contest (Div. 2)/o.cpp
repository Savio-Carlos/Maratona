#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
 
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            grid[i][j] = s[j] - '0';
        }
    }

    auto check = [&](int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    priority_queue<tuple<int,int,int>> pq;

    dist[0][0] = 0;
    pq.push({0,0,0});

    while(!pq.empty()){
        auto [d, i, j] = pq.top();
        pq.pop();

        d = -d;
        if (d != dist[i][j]) continue;

        for (int dir = 0; dir < 4; dir++){
            int nx = i + dx[dir] * grid[i][j];
            int ny = j + dy[dir] * grid[i][j];
            if (!check(nx,ny)) continue;
            int nd = d + 1;
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({-nd,nx,ny});
            }
        }
    }
    if (dist[n-1][m-1] == 1e9) cout << "IMPOSSIBLE" << endl;
    else cout << dist[n-1][m-1] << endl;
}

