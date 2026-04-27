#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    vector<int> sfx(n+1, 0);
    int cur = 0;
    for (int i = n; i ; i--){
        cur = max(cur, a[i-1]);
        sfx[i] = cur;
    }
    
    // cout << "sfx"<<endl;
    // for (int i = 0; i <= n; i++){
    //     cout << sfx[i] << " ";
    // }cout<<endl;

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, sfx[i+1] - a[i]);
        
    }
    cout << ans << endl;
}