#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;
 
vector<int> dp;
 
int find_lis(const vector<int> &a) {
    for (int u : a){
        int pos = lower_bound(dp.begin(), dp.end(), u) - dp.begin();
        if (pos == dp.size()){
            dp.push_back(u);
        }else {
            dp[pos] = u;
        }
    }
    return dp.size();
}
 
signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    cout << find_lis(a) << endl;
    //for (auto u : dp) cout << u << " ";
}