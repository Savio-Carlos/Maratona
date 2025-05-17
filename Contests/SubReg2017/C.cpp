#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

signed main() {
    winton;
    int n, l, mmc = 1;
    cin >> n >> l;
    for (int i = 0; i < n; i++){
        int a;
         cin >> a;
        mmc = lcm(mmc, a);
    }
    int ans = 1, ans2 = 1;
    for (int i = 1; i <=l; i++){
        int t = lcm(mmc,i);
        if (t > ans && t <= l){
            ans = max(ans, lcm(mmc,i));
            ans2 = i;
        }
    }
    cout << ans2 << endl;
}