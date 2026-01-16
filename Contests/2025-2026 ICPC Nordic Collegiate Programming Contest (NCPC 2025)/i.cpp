#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;

    vector<int> sz(n+1, 0);
    map<int, set<int>> follows;
    set<int> valid;
    for (int i = 1; i <= n; i++) valid.insert(i);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        sz[b]++;
        follows[a].insert(b);
        if (follows[b].find(a) != follows[b].end()){
            sz[b]--;
            sz[a]--;
        }
    }

    int mx = 0, ans = 1;
    for (int i = 1; i <= n; i++){
        if (sz[i] > mx){
            ans = i;
            mx = sz[i];
        }
    }
    cout << ans << " " << mx << endl;
}

