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
const int INF = INT_MAX;

void solve(){
    int a, x, y;
    cin >> a >> x >> y;
    bool pos = false;
    for (int i = 1; i <= 100; i++){
        if (i == a)continue;
        if (abs(i-x) < abs(x-a) && abs(y-i) < abs(y-a)){
            pos = true;
            break;
        }
    }
    if (pos) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}