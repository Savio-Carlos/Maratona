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
const int MAX = 1e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int mmc(int a, int b) {
    return a / gcd(a, b) * b;
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a){
        cin >> i;
    }
    int g = 0;
    int l = 0;
    int ans = INF;
    for (int i = 0; i < n; i++){
        g = gcd(a[i],g);
        while(l < i && g == 1 ) {
            ans = min(ans, i-l+1);
            l++;
            g = lcm(g,a[l]);
        }
    }
    cout << ans << endl;
}