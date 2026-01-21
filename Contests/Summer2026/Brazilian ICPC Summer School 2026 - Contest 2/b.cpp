#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)


void solve(){
    string line;
    while (getline(cin, line) && line.empty());
    char nn = line[0];
    int n = nn - 'A';
    
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);

    while (getline(cin, line) && !line.empty()){
        stringstream ss(line);
        char a, b;
        ss >> a >> b;
        graph[a - 'A'].push_back(b - 'A');
        graph[b - 'A'].push_back(a - 'A');
    }
    int c = 0;
    function<void(int)> dfs = [&](int v) {
        c++;
        visited[v] = true;
        for (auto u : graph[v]){
            if (visited[u]) continue;
            dfs(u);
        }
    };
    int ans = 0;
    for (int i = 0; i <= n; i++){
        if (!visited[i]){
            c = 0;
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    bool first = true;
    while(t--) {
        if (!first) cout << endl;
        solve();
        first = false;
    }
}