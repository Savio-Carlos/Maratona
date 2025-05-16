#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+7;
const int MAXS = 1e6+7;

vector<int> dp(MAXS, INF);

int main(){
    int n, ans;
    cin >> n >> ans;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    dp[0] = 0;


    for(int i = 0; i <= ans; i++){
        if(dp[i] != INF){
            for (auto u : coins){
                if (i + u <= ans) dp[i+u] = min(dp[i] + 1, dp[i+u]);
            }
        }
        
    }
    if (dp[ans] == INF) cout << -1 << endl;
    else cout << dp[ans] << endl;
}