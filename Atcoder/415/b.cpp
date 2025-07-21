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

signed main() {
    winton;
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '#'){
            ans.push_back(i+1);
        }
    }
    for (int i = 0; i < ans.size(); i+=2){
        cout << ans[i] << "," << ans[i+1] << endl;
    }
}