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

int n, dp[2*MAX][4], arr[1007];

void brute(int i, int k, int sum){
    //cout << sum << endl;
    if (k >= 0) dp[sum][k]++;
    if (k == 3) return;
    for (int ii = i+1; ii < n; ii++){
        brute(ii, k+1, sum + arr[ii]);
    }
}

signed main(){
    //winton;  
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    brute(-1,-1,4000);
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        cout << dp[4000+a][3] << endl;
    }
}