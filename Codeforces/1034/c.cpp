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
const int MAX = 1e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), pfx(n), sfx(n);
    for (auto &u : a) cin >> u;      

    for (int i = 0; i < n; i++){
        pfx[i] = a[i];
        if (i) pfx[i] = min(pfx[i-1], pfx[i]);
    }
    for (int i = n-1; i >=0; i--){
        sfx[i] = a[i];
        if (i < n-1) sfx[i] = max(sfx[i+1], sfx[i]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (a[i] == pfx[i] && a[i] <= sfx[i]){
            ans.push_back(1);
        }
        else if (a[i] == sfx[i] && a[i] >= pfx[i]){
            ans.push_back(1);
        }
        else ans.push_back(0);
    }

    for (auto u : ans) cout << u;
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}