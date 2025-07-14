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
const int MAX = 2e4+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

int dp[101][MAX];

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &u : a) {
        cin >> u;
        sum += u;
    }
    if (sum&1){
        cout << -1 << endl;
        return 0;
    }
    int half = sum/2;
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= half; j++){
            dp[i][j] = dp[i-1][j];
            if (j >= a[i-1] && dp[i-1][j - a[i-1]]) dp[i][j] = 1;
        }
    }
    if (dp[n][half]) {
        vector<int> alice, bob;
        int cur = half;
        for (int i = n-1; i >= 0; i--){
            if (cur >= a[i] && dp[i][cur - a[i]]) {
                alice.push_back(a[i]);
                cur -= a[i];
            } 
            else bob.push_back(a[i]);
        }
        sort(rall(alice));
        sort(rall(bob));
        int it1 = 0, it2 = 0;
        int soma1 = 0, soma2 = 0; 
        for (int i = 0; i < n; i++){
            if (soma1 >= soma2){
                cout << alice[it2] << " "; 
                soma2 += alice[it2++];
            }
            else{ 
                cout << bob[it1] << " ";
                soma1 += bob[it1++];
            }
        }
    }
    else cout << -1 << endl;
}