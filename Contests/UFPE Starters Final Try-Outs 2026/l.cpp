#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

struct DSU {
	vector<int> id, sz;

	DSU(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a);
        b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
        id[b] = a;
	}
};

signed main(){
    fastio;
    int n, q;
    cin >> n >> q;
    DSU dsu(27LL);
    for (int i = 0; i < n; i++){
        vector<bool> visited(26,false);
        string s;
        cin >> s;
        for (int j = 0; j < s.size() - 1; j++){

            if (visited[s[j] - 'a']) continue;
            visited[s[j] - 'a'] = 1;
            for (int k = j+1; k < s.size(); k++){
                dsu.unite(s[j] - 'a', s[k] - 'a');
            }
        }
    }
    
    while(q--){
        string a, b;
        cin >> a >> b;
        
        vector<bool> visited(26,false);
        vector<bool> visited2(26,false);
        for (int j = 0; j < a.size(); j++){
            if (visited[a[j] - 'a']) continue;
            visited[a[j] - 'a'] = 1;
            
            for (int k = 0; k < b.size(); k++){
                if (visited2[b[k] - 'a']) continue;
                visited2[b[k] - 'a'] = 1;
                int aa = dsu.find(a[j] - 'a');
                int bb = dsu.find(b[k] - 'a');
                if (aa == bb){
                    cout << "LUA" << endl;
                    goto done;
                }
            }
        }
        cout << "RYEI" << endl;
        done: continue;
    }

}

