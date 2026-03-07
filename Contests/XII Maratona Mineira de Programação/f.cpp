#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

const int MAX = 1007;
const int INF = 1e18;
const int MOD = 998244353;

int n, m, k;
int dist[MAX][MAX];
char grid[MAX][MAX];

int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};

bool check(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void flood(int i, int j){
    dist[i][j] = 0;
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for (auto xf : dx){
            for (auto yf : dy){
                int nx = xf + x;
                int ny = yf + y;
                if (check(nx,ny)){
                    if (dist[nx][ny] > dist[x][y] + 1){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx,ny});
                    }
                }

            }
        }
    }
}

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}
int modiv(int a, int b){
    return (((a % MOD )* (fastExpo(b, MOD-2) % MOD)) % MOD);
}

signed main(){
    fastio;

    cin >> n >> m >> k;
    int xi, yi;
    int tot = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            dist[i][j] = INF;
            if (grid[i][j] == 'R'){
                xi = i;
                yi = j;
            }
            if (grid[i][j] == '.') tot++;
        }
    }   
    flood(xi,yi);
    int mn = INF;
    vector<int> hmd(1e6, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 'Q'){
                mn = min(mn, dist[i][j]);
            }
            if (grid[i][j] == '.'){
                hmd[dist[i][j]]++;
            }
        }
    }   

    vector<int> pfx(1e6+1,0);
    for (int i = 1; i < 1e6; i++){
        pfx[i] = pfx[i-1] + hmd[i];
    }
    int ans = 0;
    
    for (int i = 1; i < 1e6; i++){
        if (i > mn) continue;
        int chance = 1 - modiv(hmd[i+1], k-1);
        ans = (ans + ((i * chance) % MOD)) % MOD; 
    }
    cout << ans << endl;

}