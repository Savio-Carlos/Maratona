#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

int tudo = 550;

signed main(){
    // fastio;
    vector<int> lados{4,6,8,12,20};
    vector<int> v(5,0);
    int total = 0;

    for(int i = 0; i < 5; i++){
        cin >> v[i];
        total += v[i];
    }

    vector<vector<int>> dp(total, vector<int>(tudo,0));

    for(int i = 0; i < 5; i++){
        if(v[i] != 0){
            v[i]--;
            for(int j = 1; j <= lados[i]; j++){
                dp[0][j]++;
            }
            break;
        }
    }

    int dp_state = 1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < v[i]; j++){
            // cout << v[i] << endl;
            for(int k = 1; k <= lados[i]; k++){
                for(int l = 0; l < tudo; l++){
                    if(l-k >= 0) dp[dp_state][l] += dp[dp_state-1][l-k];
                }
                
                // for(int i = 0; i < total; i++){
                //     for(int j = 0; j < 20; j++){
                //         cout << dp[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
            }
            dp_state++;
        }
    }

    // for(int i = 0; i < 5; i++){ // tipo de dado
    //     for(int k = 1; k < total; k++){ // itera pela quantidade de dados utilizados
    //         for(int l = 0; l < lados[i]; l++){ // itera pelos lados do dados
    //             for(int m = 0; m < 550; m++){ // itera pela dp
    //                 dp[k][dp[k-1][m]+l]++;
    //             }
    //         }
    //     }
    // }

    // for(int i = 0; i < total; i++){
    //     for(int j = 0; j < 25; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int debug = 0;
    vector<pair<int,int>> ans;
    for(int i = 0; i < tudo; i++){
        ans.push_back({dp[total-1][i], i});
        debug += dp[total-1][i];
    }
    cout <<"deb " << debug << endl;

    sort(ans.rbegin(), ans.rend());

    for(int i = 0; i < tudo; i++){
        if(ans[i].first > 0) cout << ans[i].second<< " ";
    }
    cout << endl;
}