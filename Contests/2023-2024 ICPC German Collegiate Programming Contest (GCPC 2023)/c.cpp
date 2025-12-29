#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
#define all(x) x.begin(), x.end()

const int MAX = 2e5+7;
const int INF = 1e9+7;

template<typename T = int> struct frac {
	T num, den;
	template<class U, class V>
	frac(U num_ = 0, V den_ = 1) : num(num_), den(den_) {
		assert(den != 0);
		if (den < 0) num *= -1, den *= -1;
		T g = gcd(abs(num), den);
		num /= g, den /= g;
	}

	friend ostream& operator<<(ostream& out, frac f) {
		out << f.num << '/' << f.den;
		return out;
	}
    friend bool operator<(const frac& l, const frac& r) {
		return l.num * r.den < r.num * l.den;
	}
	// friend frac operator=(const frac& l, const frac& r) {
	// 	return {r.num, r.den};
	// }
};

int visited[MAX], dist[2][MAX];

vector<vector<int>> graph;

void djikstra(int id, int st){
    for(int i = 0; i < MAX; i++){dist[id][i] = INF; visited[i] = 0;}
    priority_queue<pair<int,int>> pq;
    pq.push({0, st});
    dist[id][st] = 0;
    
    while(!pq.empty()){
        auto [cost, v] = pq.top();
        pq.pop();
        cost = -cost;
        if (cost != dist[id][v]) continue;
        for (auto u: graph[v]){
            int nd = cost + 1;
            if (dist[id][u] > nd){
                dist[id][u] = nd;
                pq.push({-nd, u});
            }
        }
    }
}

signed main(){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    graph.resize(n);
    vector<int> worm(k);

    for (auto &u : worm) {cin >> u; u--;}
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    djikstra(0,0);
    djikstra(1, n-1);

    // cout << "from st\n";
    // for (int i = 0; i < n; i++){
    //     cout << "i: " << dist[0][i] << endl;
    // }

    // cout << "from n-1\n";
    // for (int i = 0; i < n; i++){
    //     cout << "i: " << dist[1][i] << endl;
    // }
    int tot = 0;
    for (auto u : worm){
        tot += dist[1][u];
    }
    // cout << "tot: " << tot << endl;

    frac ans(INF, 1LL);

    for (auto u : worm){
        int cur = dist[0][u]*(k-1) + ((tot - dist[1][u]));
        frac pos(cur, k-1);
        // cout << cur << endl;
        if (pos < ans) ans = pos;
    }

    frac no(dist[0][n-1], 1LL);
    if (no < ans) cout << no << endl;
    else cout << ans << endl;
}