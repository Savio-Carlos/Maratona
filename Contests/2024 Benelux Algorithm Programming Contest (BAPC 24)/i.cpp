#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAXN = 1e6+7;
const int INF = 1e9;

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    vector<int> pref(MAXN, 0), arr(MAXN, 0), dp(MAXN, INF);
    dp[0] = 0;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int st, f; cin >> st >> f;
        //cout << st << " " << f << endl;
        arr[st+1] = f;
        mx = max(mx, st+1);
    }

    for(int i = 1; i < MAXN; i++){
        pref[i] += pref[i-1] + arr[i];
    }

    vector<tuple<int, int, int>> pass;
    for(int i = 0; i < k; i++){
        int x, y, z; cin >> x >> y >> z;
        pass.push_back({x, y, z});
    }


    for(int i = 1; i < MAXN; i++){
        if(arr[i] == 0){
            dp[i] = dp[i-1];
            continue;
        }
        dp[i] = dp[i-1] + arr[i];
        for(auto [p, f, c] : pass){
            dp[i] = min({dp[i], dp[max(i-f, 0LL)] + c, dp[max(i-f+1, 0LL)] + pref[i] - pref[max(i-f, 0LL)]});
        }
    }

    cout << dp[MAXN-1] << endl;
}