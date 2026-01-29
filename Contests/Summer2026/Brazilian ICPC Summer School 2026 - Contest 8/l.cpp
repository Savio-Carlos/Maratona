
#include <bits/stdc++.h>
using namespace std;
 
#define fastio2 ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'
 
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pfx(n,0);
    int mn = 1e9;
    for (int i = 0; i < n; i++){
        if (s[i] == 'B') pfx[i]++;
        else pfx[i]--;
        if (i) pfx[i] += pfx[i-1];
        mn = min(pfx[i], mn);
    }
    if (mn == 0){
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++){
        if (pfx[i] == mn && mn < 0){
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

 
signed main(){
    fastio2;
    int t; cin >> t;
    while(t--){
        solve();
    }
}