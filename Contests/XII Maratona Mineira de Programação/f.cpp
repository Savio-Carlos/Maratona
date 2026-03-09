#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

const int MAX = 1007;
const int MAX2 = 1e6+7;
const int INF = 1e18;
const int MOD = 998244353;

int n, m, k;
int dist[MAX][MAX];
char grid[MAX][MAX];
int fat[MAX2], invfat[MAX2];

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
        for (int di = 0; di < 4; di++){
            int nx = dx[di] + x;
            int ny = dy[di] + y;
            if (check(nx,ny) && grid[nx][ny] != '#'){
                if (dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
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
int modinv(int x) {
    return fastExpo(x, MOD - 2);
}
void build(){
    fat[0] = 1;
    for (int i = 1; i < MAX2; i++) fat[i] = (fat[i-1] * i) % MOD;
    invfat[MAX2-1] = modinv(fat[MAX2-1]);
    for (int i = MAX2 - 2; i >= 0; i--) invfat[i] = (invfat[i+1] * (i+1)) % MOD;
}
int comb(int a, int b){
    if (a > b || a < 0 || b < 0) return 0;
    return (((fat[b] * invfat[a]) % MOD) * invfat[b-a]) % MOD;
}

signed main(){
    fastio;
    build();
    cin >> n >> m >> k;
    int xi, yi;
    int tot = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
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
    vector<int> hmd(MAX2, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'Q'){
                mn = min(mn, dist[i][j]);
            }
            if (grid[i][j] == '.' && dist[i][j] != INF){
                hmd[dist[i][j]]++;
            }
        }
    }   

    vector<int> sfx(MAX2 + 1, 0);
    for (int i = MAX2 - 1; i; i--){
        sfx[i] = sfx[i+1] + hmd[i];
    }
    
    int ans = 0;
    if (mn == INF) mn = MAX2-1;
    
    int al = modinv(comb(k, tot));
    for (int i = 1; i <= mn; i++){
        ans = (ans + comb(k, sfx[i]) % MOD * al % MOD) % MOD;
    }
    
    cout << ans << endl;

}