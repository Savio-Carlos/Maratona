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
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

/*
todo caminho que tiver tamanho maior que 2 da raiz eu vou querer adicionar na resposta
*/

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> conn(n);

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
        conn[a]++;
        conn[b]++;
    }
    for (int i = 0; i < n; i++){
        if (conn[i] == n-1){
            cout << 0 << endl;
            return;
        }
    }
    int ans = INF, leaves = 0;
    for (int i = 0; i < n; i++){
        if (conn[i] == 1) leaves++;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int u : graph[i]) if (conn[u] == 1) cnt++;
        ans = min(ans, leaves-cnt);
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}