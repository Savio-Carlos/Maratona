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
const int INF = LLONG_MAX;

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

    if (o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0 && o1 != o2 && o3 != o4) return true;

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
    vector<bool> super(n);
    vector<ponto> computers(n);
    vector<linha> walls(m);
    vector<vector<pair<int,ld>>> graph(n);
    for (auto &[xi,yi] : computers) cin >> xi >> yi; 
    for (auto &[p,q] : walls) cin >> p.x >> p.y >> q.x >> q.y;
    cin >> s;
    for (int i = 0; i < s; i++){
        int x; cin >> x;
        super[x-1] = true;
    } 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            for (auto r: walls){
                linha s;
                s.p = computers[i];
                s.q = computers[j];
                if (!intersect(r,s)){
                    ponto p1 = computers[i];
                    ponto p2 = computers[j];
                    ld dist = sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
                    graph[i].push_back({j,dist});
                    graph[j].push_back({i,dist});
                }
            }
        }
    }
}