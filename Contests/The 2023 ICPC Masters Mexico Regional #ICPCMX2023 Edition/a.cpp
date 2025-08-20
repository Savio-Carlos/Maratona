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

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    int ans = 0;
    int l = 0, r = n-1;
    while (r-l >= 1){
        if (a[l] == a[r]){
            l++;
            r--;
            continue;
        }
        if (a[l] < a[r]){
            ans++;
            a[l+1] += a[l];
            l++;
        }
        else {
            ans++;
            a[r-1] += a[r];
            r--;
        }
    }
    cout << ans << endl;
}