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
    int t; 
    cin >> t;
    while(t--){
        double p,r,y;
        cin>>p>>r>>y;

        double x = y/4;

        double s = x + (x - r);
        double w = x + (x - p);

        s /= 2;
        w /= 2;




        cout << fixed << setprecision(2) << s + r << " " << w + p << " " << s << " " << w << endl;
    }
    
}