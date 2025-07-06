#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<ll> balanco(n, 0);
    for(int i = 0; i < m; i++){
        int p, v, k;
        cin >> p >> v >> k;
        for (int i = 0; i < k; i++){
            int x;
            cin >> x;
            balanco[x-1] -= v;
        }
        balanco[p-1] += (ll)k * v;
    }
    int masks = (1<<n);
    vector<ll> s(masks, 0);
    vector<char> ok(masks, 0);
    for(int i = 1; i < masks; i++){
        int b = __builtin_ctz(i);
        int prev = i ^ (1<<b);
        s[i] = s[prev] + balanco[b];
        if(s[i] == 0) ok[i] = 1;
    }
    vector<int> dp(masks, -1e9);
    dp[0] = 0;
    for(int i = 1; i < masks; i++){
        int b = __builtin_ctz(i);
        int sub = i;
        while(sub){
            if((sub & (1<<b)) && ok[sub]){
                dp[i] = max(dp[i], dp[i ^ sub] + 1);
            }
            sub = (sub - 1) & i;
        }
    }
    cout << (n - dp[masks-1]) << endl;
}