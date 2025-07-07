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
const int MAX = 2e5+7;
const int INF = LLONG_MAX;
const int MOD = 998244353;

int en[MAX], ex[MAX], dp[MAX], pfx[MAX];
bool state[MAX];

signed main(){
    winton;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> en[i] >> ex[i] >> state[i];
    }
    int ans = en[n]+1;
    for (int i = 1; i <= n; i++){
        int dist = (en[i] - ex[i]) % MOD;
        int l = 1, r = n;
        while(l <= r){
            int mid = (l+(r-l)/2);
            if (en[mid] > ex[i]){//entrada do portal mid se encontra dentro do meu portal atual
                r = mid-1;
            }
            else l = mid+1;
        }
        if (i) pfx[i] += (pfx[i-1]) % MOD;
        dp[i] = (dist + pfx[i] - pfx[l-1]) % MOD;
        pfx[i] += (dp[i]) % MOD;
        ans += (dp[i] * state[i]) % MOD;
    }
    cout << ans % MOD << endl;
}