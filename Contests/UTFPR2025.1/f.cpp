#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const ld LINF = 1e18;


struct ponto{
    int x, y;
};

struct linha{
    ponto p, q;
};

// Retorna orientação de (P, Q, R)
// 0 -> Colinear
// 1 -> Anti-horário
// -1 -> Horário
int orientation(ponto p, ponto q, ponto r){
    int val = ((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y));
    if (!val) return 0;
    return (val > 0) ? 1 : -1;
}

bool on_segment(ponto p, ponto q, ponto r){
    return (q.x <= max(p.x, r.x)) && (q.x >= min(p.x, r.x)) && (q.y <= max(p.y, r.y)) && (q.y >= min(p.y, r.y));
}

bool intersect(linha r, linha s){
    int o1 = orientation(r.p, r.q, s.p);
    int o2 = orientation(r.p, r.q, s.q);
    int o3 = orientation(s.p, s.q, r.p);
    int o4 = orientation(s.p, s.q, r.q);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && on_segment(r.p, s.p, r.q)) return true;
    if (o2 == 0 && on_segment(r.p, s.q, r.q)) return true;
    if (o3 == 0 && on_segment(s.p, r.p, s.q)) return true;
    if (o4 == 0 && on_segment(s.p, r.q, s.q)) return true;

    return false;
}

signed main() {
    winton;
    int n, m, s;
    cin >> n >> m;
    vector<int> super;
    vector<ponto> computers(n);
    vector<linha> walls(m);
    vector<vector<pair<int,ld>>> graph (n); 

    for (auto &[xi,yi] : computers) cin >> xi >> yi; 
    for (auto &[p,q] : walls) cin >> p.x >> p.y >> q.x >> q.y;
    cin >> s;
    for (int i = 0; i < s; i++){
        int x; cin >> x;
        super.push_back(x-1);
    } 
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (i == j) continue;
            bool conect = true;
            for (auto r: walls){
                linha t;
                t.p = computers[i];
                t.q = computers[j];
                if (intersect(r,t))conect = false;
            }
            if (conect){
                ponto p1 = computers[i];
                ponto p2 = computers[j];
                ld dist = sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
                graph[i].push_back({j,dist});
                graph[j].push_back({i,dist});
            }
        }
    }

    int k = super.size();
    vector<vector<ld>> d((1<<k), vector<ld> (n));

	for (int mask = 0; mask < (1 << k); mask++) for(int v = 0; v < n; v++) d[mask][v] = LINF;
    for (int i = 0; i < k; ++i) d[1 << i][super[i]] = 0;
	for (int mask = 1; mask < (1 << k); mask++) {
		for (int a = (mask - 1) & mask; a; a = (a - 1) & mask) {
			int b = mask ^ a;
			if (b > a) break;
			for (int v = 0; v < n; v++) d[mask][v] = min(d[mask][v], d[a][v] + d[b][v]);
		}
		priority_queue<pair<ld, int>> pq;
		for (int v = 0; v < n; v++) {
			if (d[mask][v] == LINF) continue;
			pq.emplace(-d[mask][v], v);
		}
		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (-ndist > d[mask][u]) continue;
			for (auto [idx, w] : graph[u]) if (d[mask][idx] > d[mask][u] + w) {
				d[mask][idx] = d[mask][u] + w;
				pq.emplace(-d[mask][idx], idx);
			}
		}
	}
	ld cost = LINF;
    for (int i = 0; i < n; i++){
        cost = min(cost, d[(1 << k) - 1][i]);
    }
    if (cost == LINF) cout << "impossivel" << endl;
    else cout << fixed << setprecision(3) << cost << endl;
}