#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 5e4+7;
const int MOD = 998244353;

//i e nosso limite inferior que podemos pegar para o J atual
//por ex todos os numeros pegam do 1, todos pegam do 2 com excessao do 2
//no final isso vai calculando o valor da dp[j] se ele consegue pegar o i atual
//quando esse for o caso ele soma a quantidade de maneiras de chegar no i na dp[j]
//vamos supor que nosso i = 3, quando j for 7, queremos adicionar todas as maneiras de chegar no 4 que temos atualmente, isso pq 4+3 = 7
//ou seja i representa o valor sendo adicionado atualmente
//dp[7] += (3)1111 (3)211 (3)22 (3)31 -> quando i = 3 adicionamos todas essas maneiras  

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        if (i == k)continue;
        for (int j = 1; j <= n; j++){
            if (j >= i){
                dp[j] += dp[j-i];
                dp[j]%=MOD;
            }
        }
            // for (int po = 0; po <= n; po++) cout << dp[po] << " ";
            // cout << endl;
    }
    //for (int i = 0; i <= n; i++) cout << dp[i] << " ";
    cout << dp[n] << endl;
}