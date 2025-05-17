#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define int long signed int long
#define endl "\n"

int dp(int x, int y, int xmax, int ymax, int sum){
    if (x > xmax || y > ymax) return sum;
    return max(dp(x+1, y, xmax, ymax, sum + x * y), dp(x, y+1, xmax, ymax, sum + x * y));
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        cout << dp(a, b, n, m, 0) << endl;
        
    }
    return 0;
}