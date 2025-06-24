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
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin >> n;
    bool pos = false;
    vector<int> a(n);
    for (int &u : a){
        cin >> u;
    }
    int ans = INF;
    for (int i = 0; i < n-1; i++){
        if (abs(a[i]-a[i+1]) <= 1) ans = 0;
    }
    //debug(ans);
    for (int i = 0; i < n-1; i++){
        int l = a[i];
        int r = a[i+1];
        if (l == r) ans = 0;
        if (i > 0){
            for (int j = 0; j < i; j++){
                if (j == i || j == i+1) continue;
                if (a[j] >= l && a[j] <= r){
                    int dist = abs(j-i);
                    ans = min(ans,dist);
                    //debug(dist);
                }
                if (a[j] >= r && a[j] <= l){
                    int dist = abs(j-i);
                    ans = min(ans,dist);
                }
            }
        }
        if (i+2 < n){
            for (int j = i+2; j < n; j++){
                if (j == i || j == i+1) continue;
                if (a[j] >= l && a[j] <= r){
                    int dist = abs(j-i)-1;
                    ans = min(ans,dist);
                    //debug(dist);
                }
                if (a[j] >= r && a[j] <= l){
                    int dist = abs(j-i)-1;
                    ans = min(ans,dist);
                }
            }
        }
    }   
    if (ans != INF) cout << ans << endl;
    else cout << -1 << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}