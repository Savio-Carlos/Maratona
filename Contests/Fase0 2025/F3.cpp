#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 4e3+7;
const int INF = INT_MAX;

int n, dp[2*MAX][5], arr[1007];

signed main(){
    winton;  
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[4000][0] = 1;
    for (int i = 0; i < n; i++){
        for (int k = 4; k > 0; k--){
            for (int sum = 0; sum <= 8000; sum++){
                if (sum-arr[i] >= 0 && sum-arr[i] <= 8000) dp[sum][k] += dp[sum-arr[i]][k-1];
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        cout << dp[4000+a][4] << endl;
    }
}