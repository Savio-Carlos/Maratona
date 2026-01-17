#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


const int INF = 1e9;

void solve(){
    int n; cin >> n;
    vector<int> arr(n+1);
    for(int i = 0; i <= n; i++) cin >> arr[i];

    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int x = arr[i];
        for(int j = 1; j * j <= x; j++){
            if(!(x%j)){
                if(i - j >= 0) dp[i] = min(dp[i], dp[i-j] + 1);
                if(x/j != j && i - x/j >= 0) dp[i] = min(dp[i], dp[i - x/j] + 1);
            }
        }
    }

    if(dp[n] == INF) cout << -1 << endl;
    else cout << dp[n] << endl;
}

signed main(){
    fastio;
    int t;

    t = 1;
    while(t--){
        solve();
    }
}