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

int calc(string s){
    int ret = 0;
    for (auto &c : s){
        ret = ret * 10 + (c-'0');
    }
    return ret;
}

void solve(){
    int l ,r;
    cin >> l >> r;
    string a, b;
    cin >> a >> b;
    string c = a + b;
    int nc = calc(c);
    int nb = calc(a);
    int k = 1, v = 1;
    for (int i = 0; i < l+r; i++) k*=10;
    for (int i = 0; i < l; i++) v*=10;

    // debug(nc);
    // debug(nb);
    int num = nc - nb;
    // debug(num2);
    // debug(num);
    int den = k-v;
    int g = gcd(num, den);
    pair<int,int> ans = {num/g, den/g};
    cout << ans.first << " " << ans.second << endl;
}

signed main() {
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
