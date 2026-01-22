#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAX = 1e6+7;

int dp[MAX];

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for (int &u : p) cin >> u;
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = 0;
    for (auto u : p){
            if (i - u < 0) continue;
            if (dp[i-u] == 0){
                dp[i] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if(dp[i]) cout << "W";
        else cout << "L";
    }

}