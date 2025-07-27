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
const int MAXN = 2e2+7;
const int MAXW = 2e4+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

int dp[MAXN][MAXW], c, n, ans = 0;
vector<int> v, w;

int knapsack(int i, int rem){
    if (rem < 0 ) return -INF;
    if (i == n) return 0;
    if(dp[i][rem] != -1) return dp[i][rem];
    return dp[i][rem] = max(knapsack(i+1, rem-w[i]) + v[i], knapsack(i+1, rem));
}

signed main(){
    winton;
    cin >> c;
    string line;
    getline(cin, line);
    getline(cin, line);
    {
        istringstream in(line);
        int x;
        while (in >> x) v.push_back(x);
    }
    getline(cin, line);
    {
        istringstream in(line);
        int x;
        while (in >> x) w.push_back(x);
    }
    n = v.size();
    memset(dp, -1, sizeof(dp));
    ans = knapsack(0,c);
    cout << max(ans, 0LL) << endl;
}
