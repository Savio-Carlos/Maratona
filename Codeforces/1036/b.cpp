#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), pfx(n+1);

    for (auto &u : a){
        cin >> u; 
    } 
    int ans = INF;
    int mn = INF;
    int sum = 0;
    for (int i = 0; i < n-1; i++){
        mn = min(a[i], mn);
        sum += mn;
        ans = min({sum+(mn*(n-i-1)),sum+a[i+1],ans});
        if (a[i] != mn){
            ans = min(ans, sum);
        }   
        //debug(ans);
    }
    
    cout << (ans) << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
