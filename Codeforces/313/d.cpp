#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double


#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)


const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;
const int K = 60;
/*
EV (sum of lengths) = sum of EV of lenghts
*/

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

ld fastExpo(ld base, int exp) {
    ld res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

struct pt {
    int x, y;
};

int pvet(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<pt> points(n);
    for (auto &[x,y] : points) cin >> x >> y;

    ld ans = 0, nn = 0;
    if (n < K) nn = fastExpo(2.0, n) - 1.0 - n - ((ld)n * (n - 1) / 2.0);

    for (int k = 1; k < n && k < K; k++){
        ld sum = 0;
        ld g = 0;
        for (int i = 0; i < n; i++){
            pt a = points[i];
            pt b = points[(i+k)%n];
        
            sum += pvet(a,b);

            int dx = abs(b.x - a.x);
            int dy = abs(b.y - a.y);
            
            g += gcd(dx, dy);
            debug(sum, g);
        }
        ld p = 0;
        if (n >= K) p = 1.0 / fastExpo(2.0, (k + 1));
        else p = (fastExpo(2.0, (n - k - 1)) - 1.0) / nn;

        ans += (ld)(sum - g) / 2.0 * p;
    }
    cout << fixed << setprecision(9) << ans+1.0 << endl;
}