#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int INF = 1e18;

signed main(){
    fastio;
    int n, total;
    cin >> n >> total;
    vector<int> v(n+1, 0), original(n);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        original[i-1] = v[i];
    }

    sort(all(v));

    vector<vector<int>> dp(total+1, vector<int>(n+1, INF));

    dp[0][0] = 0;
    for(int i = 1; i < n+1; i++){
        int acc = 0;
        for(int j = i; j > 0; j--){
            acc += (v[i] - v[j]) * (v[i] - v[j]);
        }
        dp[0][i] = acc;
    }

    for(int k = 1; k < total; k++){
        for(int i = n - k + 1; i >= k; i--){
            int acc = 0, menor = INF;
            for(int j = i - 1; j >= k; j--){
                menor = min(menor, dp[k-1][j] + acc);
                acc += (v[i] - v[j]) * (v[i] - v[j]);
            }
            dp[k][i] = menor;
            //cout << i << endl;
        }
    }

    vector<int> dias;
    dias.push_back(v[n]);
    int pos = n;
    for(int k = total - 2; k >= 0; k--){
        int acc = 0, i = pos - 1;
        for(; i >= k; i--){
            //cout << pos << " " << acc << " " << dp[k][i] << " " << dp[k+1][pos] << endl;
            if(dp[k+1][pos] == dp[k][i] + acc) break;
            acc += (v[pos] - v[i]) * (v[pos] - v[i]);
        }
        pos = i;
        dias.push_back(v[pos]);
    }

    // for(int i = 0; i < total+1; i++){
    //     for(int j = 0; j < n+1; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int i = 0; i < dias.size(); i++){
    //     cout << dias[i] << " ";
    // } cout << endl;

    for(int i = 0; i < n; i++){
        int ans = INF, cur = -1;
        for(int j = 0; j < dias.size(); j++){
            if(abs(original[i]-dias[j]) < ans){
                ans = abs(original[i]-dias[j]);
                cur = dias[j];
            }
        }
        cout << cur << " ";
    }
    cout << endl;
}