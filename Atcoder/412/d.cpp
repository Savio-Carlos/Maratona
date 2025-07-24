#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 30+7;

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<int> conexoes(n,0);
    int ans = 100;
    vector<vector<int>> grid(n, vector<int> (n));
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        grid[--a][--b] = 1;
        grid[b][a] = 1;
        conexoes[a]++;
        conexoes[b]++;
    }

    bool early = true;
    for (int j = 0; j < n; j++){
        if (conexoes[j] != 2) early = false;
    }
    if (early) {
        cout << 0 << endl;
        return 0;
    }

    for (int mask = 0;mask < (1<<n);mask++){
        //remover
        int cnt = 0;
        vector<int> con = conexoes;
        vector<vector<int>> grid2 = grid;
        vector<bool> pos(n,0);
        
        for (int i = 0; i < n; i++) if (mask&(1<<i)) pos[i] = 1;
        vdebug(pos)
        for (int j = 0; j < n-1; j++){
            for (int k = j+1; k < n; k++){
                if ((grid2[j][k] || grid2[k][j]) && (pos[j] && pos[k])){
                    // debug(j);
                    // debug(k);
                    grid2[j][k] = 0;
                    grid2[k][j] = 0;
                    con[k]--;
                    con[j]--;
                    cnt++;
                } 
            }
        }
        //vdebug(con);
        cout << endl;
        bool res = true;
        for (int j = 0; j < n; j++){
            if (con[j] != 2) res = false;
        }
        if (res) ans = min (ans,cnt);
    }


    cout << ans << endl;
}


