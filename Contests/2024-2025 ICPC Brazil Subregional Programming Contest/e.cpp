#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr)
ll const inf =1e5;

int main() {
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n,vector<ll>(n));
    ll mini=inf;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            cin>>arr[i][j];
            mini=min(mini,arr[i][j]);
        }
    }
    ll ans;
    if (mini==arr[0][0])ans=0;
    else if(mini==arr[0][n-1])ans=1;
    else if(mini==arr[n-1][n-1])ans=2;
    else if(mini==arr[n-1][0])ans=3;
    
    cout<<ans<<endl;
    
return 0;
}