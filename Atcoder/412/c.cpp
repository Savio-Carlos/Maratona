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
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &u : a) cin >> u;
    sort(a.begin()+1, a.end()-1);
    int cur = a[0];
    int ans = 0;
    if (n == 2){
        if (a[1] <= a[0]*2) cout << 2 << endl;
        else cout << -1 << endl;
        return;
    }
    for (int i = 1; i < n-1; i++){
        if (a[i+1] > cur*2 && cur*2 >= a[i]){
            cur = a[i];
            ans++;
        }
        if (cur*2 >= a[n-1]){
            cur = a[n-1];
            ans++;
            break;
        }
    }
    if (cur != a[n-1]) cout << -1 << endl;
    else cout << ans+1 << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}


