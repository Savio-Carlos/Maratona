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
    int cnt0 = 0;
    bool rest = false;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (rest){
            rest = false;
            continue;
        } 
        if (a[i] == 1) {
            cnt0 = 0;
            rest = false;
            continue;
        }
        else cnt0++;

        if (cnt0 == k){
            ans++;
            rest = true;
            cnt0 = 0;
        }
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
