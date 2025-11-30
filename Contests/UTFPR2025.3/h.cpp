#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define f first
#define s second

signed main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> amuleto(n);
    for(int i=0;i<n;i++){
        cin >> amuleto[i].s >> amuleto[i].f;
    }

    sort(all(amuleto));

    for(int i=0;i<n;i++){
        swap(amuleto[i].f, amuleto[i].s);
    }

    vector<int> dp(1e5+5);
    vector<int> hab(1e5+5);

    for(int i=0;i<n;i++){
        int custo = amuleto[i].f, poder = amuleto[i].s;

        for(int i=1e5+4;i>=0;i--){
            hab[i] = max(hab[i], poder + dp[i]);
            if(i - custo >= 0){
                dp[i] = max(dp[i], poder + dp[i-custo]);
            }
            
        }

        
    }
    // for(int i=0;i<35;i++){
    //     cout << dp[i] << " ";
    // } cout << endl;
    // for(int i=0;i<35;i++){
    //     cout << hab[i] << " ";
    // } cout << endl;

    cout << hab[m] << endl;
}