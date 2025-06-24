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

/*
 g = (f * d^2)/(m1*m2)
*/

signed main(){
    winton;
    ld m1, m2, x1, x2, f;
    cin >> m1 >> m2 >> x1 >> x2 >> f;
    ld d = fabs(x2 - x1);
    ld g = (f * d*d)/(m1*m2);
    cout << setprecision(10) << fixed << g << endl;
}