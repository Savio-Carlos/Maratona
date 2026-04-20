#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

template <typename T>
struct SparseTable {
	vector<vector<T>> m;
	
	SparseTable(vector<T>& v) {
		int n = v.size();
		int max_log = 32 - __builtin_clz(n);
		m.assign(max_log, vector<T>(n));
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; j < max_log; j++) {
			for (int i = 0; i + (1<<j) <= n; i++) {
				m[j][i] = (m[j-1][i] | m[j-1][i+(1<<(j-1))]);
			}
		}
	}
	
	T query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return (m[j][a] | m[j][b-(1<<j)+1]);
	}
};

signed main(){
    winton;
    int n, k;
    cin >> n >> k;

    vector<ull> mask(n, 0);

    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        while(m--){
            int p;
            cin >> p;
            mask[i] |= (1ULL << (p-1));
        }
    }
    SparseTable<ull> sp(mask);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        ull res = sp.query(l, r);
        vector<int> ans;
        for (int i = 0; i < k; i++){
            if (!(res & (1ULL << i))) ans.push_back(i+1);
        }
        if (!ans.size()) cout << -1;
        else for (auto u : ans) cout << u << " ";
        cout << endl;
    }
}
 