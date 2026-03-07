#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

struct DSU {
    vector<int> id, sz;
    DSU(int n) : id(n), sz(n,1) {iota(all(id), 0);}
    int find(int a) {return a== id[a] ?a : id[a] = find(id[a]);}
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if (a==b) return;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        id[b] = a; 
    }
};

signed main(){
    fastio;
    int n;
    int ans = 0;
    cin >> n;
    DSU dsu(n+1);

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        dsu.unite(a,b);
    }
    vector<int> visited(n+1);
    for (int i = 1; i <= n; i++){
        int x = dsu.find(i);
        if (visited[x]) continue;
        visited[x] = 1;
        ans += dsu.sz[x] - 1;
    }
    cout << ans << endl;
}