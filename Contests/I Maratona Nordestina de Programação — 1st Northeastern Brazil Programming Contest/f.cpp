#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(),x.end()

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return fabs(a - b) <= eps;
}

struct point {
	ld x, y;
	point(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const point p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const point p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	point operator + (const point p) const { return point(x+p.x, y+p.y); }
	point operator - (const point p) const { return point(x-p.x, y-p.y); }
	point operator * (const ld c) const { return point(x*c  , y*c  ); }
	point operator / (const ld c) const { return point(x/c  , y/c  ); }
	ld operator * (const point p) const { return x*p.x + y*p.y; }//dot
	ld operator ^ (const point p) const { return x*p.y - y*p.x; }//cross
	friend istream& operator >> (istream& in, point& p) {
		return in >> p.x >> p.y;
	}
	friend ostream& operator << (ostream& os, const point& p) {
		return os << "(" << p.x << ", " << p.y << ")";
	}
};

ld dist(point p, point q) {
	return hypot(p.y - q.y, p.x - q.x);
}

signed main(){ 
    fastio;
    int n, h;
    cin >> n >> h;
    vector<point> pts(n);
    vector<ld> raio(n);
    for (int i = 0; i < n; i++) cin >> pts[i] >> raio[i];

    int source = n;
    int sink = n + 1;
    int tot = n + 2;
    vector<vector<ld>> graph(tot, vector<ld>(tot, DINF));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ld d = dist(pts[i], pts[j]) - raio[i] - raio[j];
            graph[i][j] = graph[j][i] = max(0.0, d);
        }
        graph[source][i] = graph[i][source] = max(0.0, pts[i].y - raio[i]);
        graph[i][sink] = graph[sink][i] = max(0.0, h - pts[i].y - raio[i]);
    }
    graph[source][sink] = graph[sink][source] = h;

    vector<ld> dd(tot, DINF);
    priority_queue<pair<ld,int>> pq;
    dd[source] = 0;
    pq.push({0.0,source});

    while(!pq.empty()){
        auto [d, v] = pq.top();
        d = -d;
        pq.pop();
        if (d != dd[v]) continue;
        for (int u = 0; u < tot; u++){
            ld w = graph[v][u];
            if (w == DINF) continue;
            ld nd = d + w;
            if (nd < dd[u]) {
                dd[u] = nd;
                pq.push({-nd, u});
            }
        }
    }

    cout << fixed << setprecision(10) << dd[sink] << endl;
}