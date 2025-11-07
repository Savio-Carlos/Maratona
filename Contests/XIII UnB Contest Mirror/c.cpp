#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int>dp(n);
    for(int i=n-1;i>=0;i--){
        dp[i] = max(v[i],(int)0);
        for(int j=i+1;j<min(i+k+1,n);j++){
            if(i+k < n){
                dp[i] = max({dp[i],dp[j],v[i]+dp[i+k]});
            } else {
                dp[i] = max({dp[i],dp[j]});
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     cout << dp[i] << " ";
    // } cout << endl;

    cout << dp[0] << endl;
    return 0;
}