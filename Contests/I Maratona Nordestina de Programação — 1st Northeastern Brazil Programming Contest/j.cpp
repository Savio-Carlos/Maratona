#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(),x.end()

/*
ver maior numero no intervalo e quantos numeros tem a direita e a esquerda dele
se for 0 em algum dos lados ou impar entao o adilson ganha
se for par o reginaldo ganha
*/

struct SparseTable {
	vector<vector<int>> m;
	
	SparseTable(vector<int>& v) {
		int n = v.size();
		int max_log = 32 - __builtin_clz(n);
		m.assign(max_log, vector<int>(n));
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; j < max_log; j++) {
			for (int i = 0; i + (1<<j) <= n; i++) {
				m[j][i] = max(m[j-1][i], m[j-1][i+(1<<(j-1))]);
			}
		}
	}
	
	int query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return max(m[j][a], m[j][b-(1<<j)+1]);
	}
};

signed main(){
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> a(n), pos(n+1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]] = i+1;
    }
    SparseTable st(a);
    while(q--){
        int l, r;
        cin >> l >> r;
        int mx = st.query(l-1, r-1);
        int onde = pos[mx];
        int tot = (r - onde) + (onde - l);
        if (onde == r or onde == l or (tot&1)) cout << "Adilson" << endl;
        else cout << "Reginaldo" << endl;
    }
    
} 
