#include <bits/stdc++.h>
using namespace std;

#define fastio2 ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


int d1[] = {0, 1, 0, -1, 1, -1, 1, -1};
int d2[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int INF = 1e18;

void solve(){
	int n, m; cin >> n >> m;
	char grid[n][m];
	map<char,vector<pair<int, int>>> pos;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
			pos[grid[i][j]].push_back({i, j});
		}
	}
	vector<vector<int>> dist(n, vector<int>(m, 1));
	int ans = 1;
	for(int i = 0; i < 25; i++){
		char a = 'A' + i;
		char nxt = a + 1;
		for(auto [x, y] : pos[a]){
			for(int j = 0; j < 8; j++){
				int dx = x + d1[j];
				int dy = y + d2[j];
				if(dx < 0 || dx >= n) continue;
				if(dy < 0 || dy >= m) continue;
				if(grid[dx][dy] == nxt){
					dist[dx][dy] = max(dist[dx][dy], dist[x][y] + 1);
					ans = max(ans, dist[dx][dy]);
				}
			}
		}
	}
	cout << ans << endl;
}

signed main(){
    fastio2;
    int t=1;
    while(t--){
        solve();
    }
}