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

*/

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < n/2; i++){
        ans = max(ans,(a[i]+a[n-i-1])/2);
    }
    cout << ans << endl;
}