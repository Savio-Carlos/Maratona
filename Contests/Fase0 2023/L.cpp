#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXN = 1e3+7;

int grid[MAXN][MAXN];

signed main() {
    winton;
    int n, m;
    cin >> n >> m;
    int s;
    cin >> s;
    for (int i = 0; i < s; i++){
        int x,y,r;
        cin >> x >> y >> r;
        int stx = max(1LL, x - r);
        int edx = min(n, x + r);
        int sty = max(1LL, y - r);
        int edy = min(m, y + r);
        for (int j = stx; j <= edx; j++){
            grid[j][sty]++;
            grid[j][edy+1]--;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            grid[i][j] += grid[i][j-1];
        }
    }
    map<int,int> mp;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            mp[grid[i][j]]++;
        }
    }
    int ans = 0;
    for (auto u : mp){
        ans += u.first * u.second;
    }
    cout << ans/(n*m) << endl;
}