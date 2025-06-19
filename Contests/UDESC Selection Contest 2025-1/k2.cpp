#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
/*
comecar do final e guardar a quantidade de intervalos necessarios dali pra frente
guardo num map o numero de intervalos necessarios a partir do intervalo daquele numero
se eu consigo fazer um intervalo entao minha dp e o minimo entre dp[i] atual e o valor de intervalos necessarios caso eu faca essa juncao
if(mp.find(a[i]) != mp.end())dp[i] = min(dp[i], mp[a[i]]+1)
guardo no meu map apenas a melhor instancia de intervalo daquele valor
pode ser que tenha um intervalo menor que minimize a quantidade de intervalos depois dele
*/
int n, a[MAX], dp[MAX];

signed main(){
    winton;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dp[i] = INF;
    }
    map<int,int> mp;
    for(int i = n-1; i >= 0; i--){
        dp[i] = dp[i+1] + 1;
        if(mp.find(a[i]) != mp.end()){
            dp[i] = min(dp[i], mp[a[i]]+1);
            mp[a[i]] = min(dp[i+1],mp[a[i]]);
        }
        else {
            mp[a[i]] = dp[i+1];
        }
    }
    // for (int i = 0; i < n; i++){
    //     cout << dp[i] << " ";
    // }cout << endl;
    cout << dp[0] << endl;
}