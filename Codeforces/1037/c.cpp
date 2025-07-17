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
const int INF = LLONG_MAX;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    } 
    int cur = a[k-1];
    sort(all(a));
    int start;
    bool pos = true;
    for (int i = 0; i < n-1; i++){
        if (a[i+1] > cur){
            start = i;
            break;
        } 
    }
    //debug(start);
    int water = 0;
    for (int i = start; i < n-1; i++){
        // debug(water);
        if (a[i] == mx) break;

        int cost = (a[i+1] - a[i]);
        water += cost;
        if (water > a[i]){
            pos = false;
            break;
        }
    }
    if (pos) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
