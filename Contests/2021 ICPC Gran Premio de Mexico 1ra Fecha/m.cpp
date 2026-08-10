#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

struct DSU {
	vector<int> id, sz;

	DSU(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	bool unite(int a, int b) {
		a = find(a);
        b = find(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
        id[b] = a;
        return true;
	}
};

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(360);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }
    int ans = 0;
    for (int offset = 1; offset <= 359; offset++){
        DSU dsu(360);
        
        for (int i = 0; i < 360; i++){
            if (a[i] && a[(i + offset) % 360]) {
                dsu.unite(i, (i + offset) % 360);
            }
        }
        int pairs = 0;
        for (int i = 0; i < 360; i++) {
            if (a[i] && dsu.find(i) == i) {
                pairs += dsu.sz[dsu.find(i)] / 2;
            }
        }
        ans = max(ans, pairs);
    }
    cout << ans << endl;
}