#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e3+7;

int dp[MAXN][MAXN];

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main() {
    winton;
    setIO("nocross");
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (abs(a[i-1]-b[j-1]) <= 4){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    //for (int i = 0; i <= n; i++){
        //for (int j = 0; j <= n; j++){cout<<dp[i][j]<<" ";}cout<<endl;}
    cout << dp[n][n] << endl;
}