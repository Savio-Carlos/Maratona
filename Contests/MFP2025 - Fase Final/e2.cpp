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
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    winton;
    int n, mr;
    cin >> n >> mr;
    vector<int> xi(n), mi(n);
    for (auto &u : xi) cin >> u;
    for (auto &u : mi) cin >> u;
    vector<ld> ans;
    for (int i = 0; i < n-1; i++){
        ld l = xi[i], r = xi[i+1];
        for (int k = 0; k <= 60; k++){
            ld mid = (l+r)/2;
            ld ff = 0, ft = 0;
            for (int j = 0; j <= i; j++) ft += (mi[j]) / ((mid - xi[j]) * (mid - xi[j]));
            for (int j = i+1; j < n; j++) ff += (mi[j]) / ((xi[j] - mid) * (xi[j] - mid));
            
            if (ft > ff) l = mid;
            else r = mid;
        }
        ans.push_back((l+r)/2);
    }
    cout << ans.size() << endl;
    for (auto u : ans) cout << fixed << setprecision(10) << u << " ";
}