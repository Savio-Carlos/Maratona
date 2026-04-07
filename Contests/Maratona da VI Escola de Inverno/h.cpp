#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define winton ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> outdeg(n+1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        outdeg[a]++;
    }

    vector<int> fat(n+1,1);
    for (int i = 1; i <= n; i++) fat[i] = fat[i-1] * i;

    int ans = 0;
    function<void(int, int)> dfs = [&](int v, int len) {
        if(outdeg[v] == 0) ans += fat[n-len+1];
        for (auto u :graph[v]) dfs(u,len+1);
    };

    dfs(1,1);
    cout << ans << endl;
}