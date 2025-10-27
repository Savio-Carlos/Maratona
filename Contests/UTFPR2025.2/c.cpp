#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e12;
const int MAXN = 107;
int n, m, q;
int d[MAXN][MAXN];

signed main() {
    fastio;
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++) d[i][j] = INF;
    
    cin >> n >> m >> q; 
    double h = 1.82;
    for(int i = 0; i < m; i++){
        int a, b, dis;
        double altura; 
        cin >> a >> b >> dis >> altura;
        a--, b--;
        double res = altura/h;
        if(res >= 1.25 || altura == 0.0){
            d[a][b] = min(d[a][b], dis);
            d[b][a] = min(d[b][a], dis);
        }
    }

    for(int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++) cout << d[i][j] << " ";
    //     cout << endl;
    // }
        
    int cur = 0;
    while(q--){
        int x; cin >> x;
        x--;
        if(d[x][cur] == INF) cout << -1 << endl;
        else{
            cout << d[x][cur] << endl;
            cur = x;
        }
    }
}