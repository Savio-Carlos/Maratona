#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MOD = 1e9+7;
const int INF = INT_MAX;

signed main () {
    winton;
    int g,m;
    cin >> g >> m;
    int sum = 0;
    vector<int> pyramides, dp(g+1, 0);
    vector<pair<int,int>>dp2(g+1, {INF,0});
    for (int i = 1; sum+(i*i) <= g; i++){
        sum+=i*i;
        pyramides.push_back(sum);
    }
    dp[0] = 1;
    for(int i = 1; i <= g; i++){
        for (auto u : pyramides){
            if (i - u >= 0) dp[i] = (dp[i] + dp[i-u]) % MOD;
        }
    }

    dp2[0] = {0, 1};
    for(int i = 1; i <= g; i++){
        for (auto u : pyramides){
            if (i - u >= 0 && dp2[i-u].first != INF) {
                int qtd = dp2[i-u].first + 1;
                if (qtd < dp2[i].first) {
                    dp2[i] = {qtd, dp2[i-u].second};
                } else if (qtd == dp2[i].first) {
                    dp2[i].second = (dp2[i].second + dp2[i-u].second) % MOD;
                }
            }
        }
    }
    
    if (m == 1) cout << dp[g]%MOD << endl;
    else cout << dp2[g].second << endl;
}

/*
dp2[i].first tracks the minimum number of pyramids
dp2[i].second tracks the number of ways to achieve that minimum

*/