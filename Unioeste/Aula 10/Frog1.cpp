#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+7;
const int MAXS = 1e6+7;

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    vector<int> dp(n, INF);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for (int u = 1; u <= 2; u++){
            if (i+u < n){
                dp[i+u] = min(dp[i] + abs(height[i] - height[i+u]), dp[i+u]);
            }
        }
    }
    cout << dp[n-1] << endl;
}