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
const int MAX = 1e6+7;
const int INF = LLONG_MAX;
const int MOD = 998244353;

struct circle{
    ld x, y, raio;
};

signed main(){
    winton;
    ld x1, x2, y1, y2;
    int n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    vector<circle> cs(n);
    for (int i = 0; i < n; i++){
        ld a, b, r;
        cin >> a >> b >> r;
        cs[i] = {a,b,r};
    }
    ld A = x2 - x1;
    ld B = y2 - y1;
    ld C = A * A + B * B;
    ld ans = 0;
    for (int i = 0; i < n; i++){   
        auto [x, y, r] = cs[i]; 
        ld wx = x - x1;
        ld wy = y - y1;
        ld t = (wx * A + wy * B) / C;
        ld um = 1.0;
        ld zero = 0.0;
        t = max(zero, min(um, t));
        ld px = x1 + t * A;
        ld py = y1 + t * B;
        ld dx = x - px;
        ld dy = y - py;
        ld dist = sqrt(dx*dx + dy*dy);
        if (dist <= r){
            ans += r - dist;
        }
    }
    cout << fixed << setprecision(4) << ans << endl;
}