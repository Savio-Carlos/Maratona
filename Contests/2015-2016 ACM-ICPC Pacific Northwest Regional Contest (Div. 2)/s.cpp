#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

const int MAX = 1e6 + 7;

int dp[MAX];

signed main(){
    winton;
    int n;
    cin >> n;
    map<int, pair<int,int>> mp;

    for (int i = 0; i < n; i++){
        int m,f,w;
        cin >> m >> f >> w;
        mp[m] = {f,w};
    }

    for (int i = MAX-1; i >= 0; i--){
        dp[i] = dp[i+1];
        if (mp.count(i)){
            auto [f, w] = mp[i];
            int next = min(MAX-1, i + w);
            dp[i] = max(dp[i], dp[next] + f);
            // cout << "i: " << i << " next: " << next << endl; 
        }
    }
    cout << dp[0] << endl;
}

