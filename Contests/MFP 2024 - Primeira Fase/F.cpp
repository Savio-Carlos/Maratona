#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MOD = 1e8;
const int MAXN = 1e2+7;
const int MAXM = 1e4+7;

signed main(){  
    winton;
    int n;
    cin >> n;
    int ans = 0;
    if (n&8) ans++;
    if (n&4) ans++;
    if (n&2) ans++;
    if (n&1) ans++;
    cout << ans << endl;
}
