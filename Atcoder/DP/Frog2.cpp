#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+1;
const int LOG = 20;
const int INF = INT_MAX;

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    vector<int> dp(MAXN, INF), height(MAXN, 0);

    for (int i = 0; i < n; i++){
        cin >> height[i];
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        for (int u = 1; u <= k; u++){
            if (i + u <= n){
                dp[i+u] = min(dp[i+u],abs(height[i]-height[i+u])+dp[i]);
            }
        }
    }
    cout << dp[n-1] << endl;
}