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
const int INF = LLONG_MAX;

signed main(){
    winton;
    int n, mr;
    cin >> n >> mr;
    vector<int> x(n), m(n);
    for(auto &u : x) cin >> u;
    for(auto &u : m) cin >> u;
    vector<ld> ans;
    for(int i = 0; i < n-1; i++){
        ld l = x[i], r = x[i+1];
        for(int k = 0; k < 100; k++){
            ld mid = (l + r) / 2;
            ld lf = 0, rf = 0;// rf / tick 
            
            for(int j = 0; j <= i; j++) lf  += m[j] / ((mid - x[j]) * (mid - x[j]));
            for(int j = i+1; j < n; j++) rf += m[j] / ((x[j] - mid) * (x[j] - mid));

            if(lf > rf) l = mid;
            else r = mid;
        }
        ans.push_back((l + r) / 2);
    }

    cout << ans.size() << endl;
    for(ld p : ans) cout << fixed << setprecision(9) << p << " ";
}
