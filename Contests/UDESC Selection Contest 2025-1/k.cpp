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
pegar e separar todos os intervalos de cada numero
sempre pegar o menor intervalo possivel, mas o fim desse intervalo tambem sera o comeco de outro(possivelmente)
fazer knapsack, sempre que eu chegar no mesmo lugar mas com um numero maior de intervalos eu paro
*/
int n, a[MAX], dp[MAX], intervalos[MAX];

void solve(int idx, int qtd){
    if (dp[idx] != INF && qtd > dp[idx]) return;
    dp[idx] = qtd;
    for (int i = idx; i < min(intervalos[i], n); i++){
        if (intervalos[i] != INF) solve(intervalos[i], qtd);
        qtd++;
    }
}

signed main(){
    winton;
    cin >> n;
    for (int i = 0; i < n; i++) intervalos[i] = dp[i] = INF;
    map<int,int> last;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (last.find(a[i]) != last.end()){
            intervalos[last[a[i]]] = i;
        }
        last[a[i]] = i;
    }
    solve(0,1);
    int ans = INF;
    // for (int i = 0; i < n; i++){
    //     cout << dp[i] << " "; 
    // }
    for (int i = 0; i < n; i++){
        if(dp[i] == INF) continue;
        ans = min(ans, (dp[i] + n-i-1));
    }
    cout << ans << endl;
}