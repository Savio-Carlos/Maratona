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

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        if (i&1){
            if (i < n-1) cout << 3 << " ";
            else cout << 2 << " ";
        } 
        else cout << -1 << " ";
    }
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
