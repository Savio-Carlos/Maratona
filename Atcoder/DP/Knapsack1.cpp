#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 101;
const int MAXW = 1e5+7;
const int MOD = 1e9+7;
const int INF = 1e12;

int dp[MAXN][MAXW], weight, n, ans = 0;; 
vector<pair<int,int>> items(MAXN);

int knapsack(int i, int w){
    if (w < 0 ) return -INF;
    if (i == n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    auto [u, v] = items[i];
    return dp[i][w] = max(knapsack(i+1, w-u) + v, knapsack(i+1, w));
}

signed main(){
    winton;
    cin >> n >> weight;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        items[i] = {a,b};
    }
    memset(dp, -1, sizeof(dp));
    ans = knapsack(0,weight);
    cout << ans << endl;
}

