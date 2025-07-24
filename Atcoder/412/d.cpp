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
        --a, --b;
        grid[a][b] = 1;
        grid[b][a] = 1;
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    
    do {
        //vdebug(p);
        //1 ciclo
        vector<vector<int>> cur(n, vector<int> (n));
        for (int i = 0; i < n; i++){
            cur[p[i]][p[(i+1)%n]] = 1;
            cur[p[(i+1)%n]][p[i]] = 1;
        }

        int cnt1 = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] != cur[i][j]) cnt1++;
            }
        }
        ans = min (ans,cnt1/2);


        //2ciclos
        for (int d = 3; d <= n-3; d++){
            vector<vector<int>> cur2(n, vector<int> (n));
            for (int i = 0; i < d; i++){
                cur2[p[i]][p[(i+1)%d]] = 1;
                cur2[p[(i+1)%d]][p[i]] = 1;
            }
            for (int i = 0; i < n-d; i++){
                cur2[p[i+d]][p[(i + 1) % (n - d) + d]] = 1;
                cur2[p[(i + 1) % (n - d) + d]][p[i+d]] = 1;
            }
            int cnt2 = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (grid[i][j] != cur2[i][j]) cnt2++;
                }
            }
            ans = min (ans,cnt2/2);
        }

    } while(next_permutation(all(p)));

    cout << ans << endl;


}


