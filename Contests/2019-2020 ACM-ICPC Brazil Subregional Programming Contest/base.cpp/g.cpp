#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

template<typename T> struct hungarian{
    int n;
    vector<vector<T>> a;
    vector<T> u, v;
    vector<int> p, way;
    T inf;

    hungarian(int _n, vector<vector<T>> _a){
        n = _n; 
        u.resize(n+1);
        v.resize(n+1);
        p.resize(n+1); 
        way.resize(n+1);
        a = _a;
        inf = INT_MAX;
    }

   	pair<T, vector<int>> assignment() {
		for (int i = 1; i <= n; i++) {
			p[0] = i;
			int j0 = 0;
			vector<T> minv(n+1, inf);
			vector<int> used(n+1, 0);
			do {
				used[j0] = true;
				int i0 = p[j0], j1 = -1;
				T delta = inf;
				for (int j = 1; j <= n; j++) if (!used[j]) {
					T cur = a[i0-1][j-1] - u[i0] - v[j];
					if (cur < minv[j]) minv[j] = cur, way[j] = j0;
					if (minv[j] < delta) delta = minv[j], j1 = j;
				}
				for (int j = 0; j <= n; j++)
					if (used[j]) u[p[j]] += delta, v[j] -= delta;
					else minv[j] -= delta;
				j0 = j1;
			} while (p[j0] != 0);
			do {
				int j1 = way[j0];
				p[j0] = p[j1];
				j0 = j1;
			} while (j0);
		}
		vector<int> ans(n);
		for (int j = 1; j <= n; j++) ans[p[j]-1] = j-1;
		return make_pair(-v[0], ans);
	}
};

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<vector<double>> grid(n, vector<double> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            grid[j][i] = -log(double(x));    
        }
    }
    hungarian hung(n, grid);
    pair<int, vector<int>> res = hung.assignment();
    for (auto u : res.second) cout << u+1 << " ";
}