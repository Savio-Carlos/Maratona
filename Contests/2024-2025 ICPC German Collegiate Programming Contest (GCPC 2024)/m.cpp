#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

const int MAX = 2e5+7;

int n;
vector<int> a;
int solve(int x){
    vector<int> cur(n);
    iota(cur.begin(), cur.end(), x);
        int diff = 0;
        for (int i = 0; i < n; i++){
            diff += abs(cur[i] - a[i]);
        }
    return diff;
}

signed main(){
    fastio;
    cin >> n;
    a.resize(n);
    for (auto &u : a){
        cin >> u;
    }
    int ans = -3*1e5;
    for(int i=4*1e5; i >= 1; i /= 2){
        while(solve(ans+i) > solve(ans+i+1)){
            ans += i;
            // cout<<ans<<endl;
        }
    }
    // cout << ans << endl;
    cout << solve(ans+1) << endl;
}