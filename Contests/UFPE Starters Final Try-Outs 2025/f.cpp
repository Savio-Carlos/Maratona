 #include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int MAX = 1e4+12;
const int INF = 1e18;

int x,n;
pair<int,int> a[MAX];
int v[MAX], p[MAX];
int dp[MAX];

signed main(){
    fastio;
    cin >> x >> n;
    for (int i = 0; i < MAX; i++) dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> p[i] >> v[i];
        for (int j = x; j >= 0; j--){
        for (int k = 1; k <= p[i]; k++){
            int nxt = j + k;
            dp[nxt] = min(dp[nxt], v[i] + dp[j]);
            }
        }
    }
    // for (int i = 0; i <= 10; i++) cout << dp[i] << " ";
    // cout << endl;
    if (dp[x] == INF) cout << -1 << endl;
    else cout << dp[x] << endl;
}