#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int INF = 1e18;

signed main () {
    winton;
    int n, k;
    cin >> n >> k;
    int price[k][n];
    vector<vector<int>> total(1<<k, vector<int>(n, INF));

    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            cin >> price[i][j];
        }
    }
    total[0][0] = 0;
    for (int x = 0; x < k; x++){
            total[1 << x][0] = price[x][0];
    }
    for (int d = 1; d < n; d++) {
        for (int s = 0; s < (1<<k); s++) {
            total[s][d] = total[s][d-1];
            for (int x = 0; x < k; x++) {
                if (s&(1<<x)) {
                    total[s][d] = min(total[s][d],
                    total[s^(1<<x)][d-1]+price[x][d]);
                }
            }
        }
    }
    int ans = total[(1 << k) - 1][n-1];
    cout << (ans == INF ? -1 : ans) << endl;


    for (int i = 1; i < (1<<k); i++){
        for (int j = 0; j < n; j++){
            cout << total[i][j] << " ";
        }
        cout << endl;
    }
}