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
const int INF = INT_MAX;

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> o(n);
        for (auto &u : o) cin >> u;
        vector<int> s = o;
        sort(rall(s));
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == o[i]) ans++;
        }
        cout << ans << endl;
    }
}