#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cout << x << " "; 
#define endl '\n'

const int INF = 1e18;

template<typename T> struct ODT {
	set<tuple<int, int, T>> se;

	vector<tuple<int, int, T>> update(int l, int r, T val) {
		auto it = se.upper_bound({r, INF, val});
		if (it != se.begin() and get<1>(*prev(it)) > r) {
			auto [L, R, V] = *--it;
			se.erase(it);
			se.emplace(L, r, V), se.emplace(r+1, R, V);
		}
		it = se.lower_bound({l, -INF, val});
		if (it != se.begin() and get<1>(*prev(it)) >= l) {
			auto [L, R, V] = *--it;
			se.erase(it);
			se.emplace(L, l-1, V), it = se.emplace(l, R, V).first;
		}
		vector<tuple<int, int, T>> ret;
		for (; it != se.end() and get<0>(*it) <= r; it = se.erase(it))
			ret.push_back(*it);
		se.emplace(l, r, val);
		return ret;
	}
	T query(int i) {
		auto it = se.upper_bound({i, INF, T()});
		if (it == se.begin() or get<1>(*--it) < i) return -1; // nao tem
		return get<2>(*it);
	}
};

signed main(){
    fastio;
    int n;
    cin >> n;
    ODT<int> odt;
    map<int, set<pair<int,int>>> seg;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        odt.se.emplace(i, i, a);
        seg[a].insert({i, i});
    }
    int m;
    cin >> m;
    while (m--) {
        int c;
        cin >> c;
        if (seg[c].size() == 0) continue;
        int l = seg[c].begin()->first;
        int r = seg[c].rbegin()->second;
        if (l == r) continue;
        auto removed = odt.update(l, r, c);
        for (auto& [sl, sr, oldc] : removed) {
            seg[oldc].erase({sl, sr});
        }
        seg[c].insert({l, r});
    }
    for (int i = 1; i <= n; i++) {
        cout << odt.query(i) << " ";
    }
    cout << endl;
}