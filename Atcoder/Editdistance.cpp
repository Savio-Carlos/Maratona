#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 5*(1e3)+7;

int dp[MAXN][MAXN];

signed main(){
    winton;
    string a, b;
    cin >> a >> b;  
    
    for (int i = 1; i <= (int)a.length(); i++){
        dp[i][0] = i;
        for (int j = 1; j <= (int)b.length(); j++){
            dp[0][j] = j;
            if (a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                dp[i][j]++;
            }
        }
    }
    cout << dp[(int)a.length()][(int)b.length()] << endl;
}
/*
1
FOOD
MONEY
0 1 2 3 4 5 
1 1 2 3 4 5
2 2 1 2 3 4
3 3 2 2 3 4
4 4 3 3 3 4
4
*/
