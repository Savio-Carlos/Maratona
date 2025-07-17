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

void solve(){
    int n;
    ld x1, x2, y1, y2;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    ld dist = sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));
    //debug(dist);
    vector<int> a(n);
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(a[i], mx);
    }
    ld alcancemin = max((ld)0.0, (ld)2*mx - sum);
    if(dist <= sum && dist >= alcancemin) cout << "Yes\n";
    else cout << "No\n"; 

}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
