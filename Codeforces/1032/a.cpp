#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

void solve(){
    int n, s;
    cin >> n >> s;
    int mx = 0, mn = INF;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        mx = max(a,mx);
        mn = min(a,mn);
    }
    int ans = min(abs(s-mn)+(mx-mn), abs(s-mx)+(mx-mn));
    cout << ans << endl;
    
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}