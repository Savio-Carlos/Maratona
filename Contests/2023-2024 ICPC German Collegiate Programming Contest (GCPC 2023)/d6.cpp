#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)


signed main(){
    fastio;
    int tot = 0;
    vector<int> lados{4,6,8,12,20};
    vector<int> dados;
    int total = 0;
    for(int i = 0; i < 5; i++){
        int x; cin >> x;
        int k = lados[i]*x;
        total += k;
        while(x--){
            dados.push_back(lados[i]);
        }
    }
    
    int n = dados.size();
    vector<vector<double>> dp(n, vector<double>(total+7, 0));

    for(int i = 1; i <= dados[0]; i++){
        dp[0][i] = 1;
    }
    //usando i dados
    for(int j = 1; j <= total; j++){
        for(int i = 1; i < n; i++){
            if(!dp[i-1][j]) continue;
            for(int k = 1; k <= dados[i]; k++) dp[i][k+j]+= dp[i-1][j];
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 1; j <= total; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<pair<int, int>> valores;
    for(int i = 1; i <= total; i++){
        if(dp[n-1][i]) valores.push_back({dp[n-1][i], i});
    }
    
    sort(valores.rbegin(), valores.rend());
    for(auto [a,b] : valores){
        cout << b<< " ";
    }
    cout << endl;
}