#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 101;
const int MAXV = 1e5+7;
const int INF = LLONG_MAX;

int dp[MAXN][MAXV], weight, n, ans = 0;
vector<pair<int,int>> items(MAXN);

// dp para achar o peso para i items
// guardar no vetor de valor o menor peso encontrado para aquela soma


int knapsack(int i, int v){
    if (dp[i][v] != -1) return dp[i][v];
    if (i == n) return v == 0 ? 0 : INF;
    auto [peso, valor] = items[i];

    int deixar = knapsack(i + 1, v);

    int rem = v - valor > 0 ? v-valor : 0; 

    int pegar = knapsack(i + 1, rem);

    if (pegar != INF) {
        pegar += peso;
    }
    
    return dp[i][v] = min(deixar, pegar);
}

signed main(){
    winton;
    cin >> n >> weight;
    int total = 0;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        items[i] = {a,b};
        total += b;
    }
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i <= total; i++){
        if (knapsack(0,i) <= weight){
            ans = i;
        }
    }
    //cout << dp[1][90] << endl;
    cout << ans << endl;
}

