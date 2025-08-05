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
/*
n(s) = r + s
e(s) = (y+p-r)/2 - s
w(s) = (y-p-r)/2 - s
s(s) = s

n(s) = a + s
e(s) = b - s
w(s) = c - s
s(s) = s

M = max{(|a+s|), (|b-s|), (|c-s|), (|s|)}

|a+s| <= M    ->     -M-a <= s <= M-a
|b-s| <= M    ->     -M+b <= s <= M+b
|c-s| <= M    ->     -M+c <= s <= M+c
|s|   <= M    ->     -M   <= s <= M

achar o minimo e maximo do intervalo de s

smin(M) = max{−M−a,c−M,−M,b−M},
smax(M) = min{M−a,c+M,M,b+M},
​
como todos tem -M ou M podemos cortar

smin = max(-a,b,c,0)
smax = min(-a,b,c,0)
*/
signed main(){
    winton;
    int q;
    cin >> q;
    while(q--){
        ld p, r, y;
        cin >> p >> r >> y;
        ld a = r;
        ld b = (y+p-r)/2;
        ld c = (y-p-r)/2;

        ld smin = max({-a,b,c,(ld)0.0});
        ld smax = min({-a,b,c,(ld)0.0});

        ld s = (smin+smax)/2;

        ld n = r+s;
        ld e = b-s;
        ld w = c-s;

        cout << fixed << setprecision(7) << n << ' ' << e << ' ' << s << ' ' << w << ' ' << endl;
    }
}