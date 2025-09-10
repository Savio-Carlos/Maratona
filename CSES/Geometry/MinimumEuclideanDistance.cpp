#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


struct point {
    int x, y;
    point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    bool operator < (const point p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}

    bool operator == (const point p) const {
		return x == p.x and y == p.y;
	}

    point operator + (const point& p) const { return point(x + p.x, y + p.y); }
    point operator - (const point& p) const { return point(x - p.x, y - p.y); }
    template<typename U>
    point operator * (const U c) const { return point(x * c, y * c); }
    auto operator * (const point& p) const { return (int)x * p.x + (int)y * p.y; }
    auto operator ^ (const point& p) const { return (int)x * p.y - (int)y * p.x; }

    friend istream& operator >> (istream& in, point& p) { return in >> p.x >> p.y; }
    friend ostream& operator << (ostream& os, const point& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

struct line {
	point p, q;
	line() {}
	line(point p_, point q_) : p(p_), q(q_) {}
    
    friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}

    friend ostream& operator << (ostream& os, line& r) {
		return os << "[" << r.p << " -> " << r.q << "]";
	}
};

int sq(point p){
    return p.x*p.x + p.y*p.y;
}

int abs(point p){
    return sqrt(sq(p));
}

//checa se dois vetores sao perpendiculares
bool perpendicular(point v, point w){
    return (v*w == 0);
}

//ccw, 0 colineares, -1 r a direita, 1 r a esquerda
int orientation(point p, point q, point r){
    int val = ((q-p) ^ (r-p));
    if (!val) return 0;
    return (val > 0) ? 1 : -1;
}

//checa se um ponto esta contido no angulo do segmento pq e pr
bool onAngle (point p, point q, point r, point g){
    if (!orientation(p,q,r)) return false;
    if (orientation(p,q,r) > 0) swap(q,r);
    return orientation(p,q,g) >= 0 && orientation(p,r,g) <= 0; 
}

// quadrante de um ponto
int quad(point p) { 
	return (p.x<0)^3*(p.y<0);
}

//dist quadrada de dois pontos
int dist2(point p, point q){
    return sq(p.x - q.x) + sq(p.y - q.y);
}

// 2 * area com sinal
int sarea2(point p, point q, point r) { 
	return (q-p)^(r-q);
}

//checa se o poligono e convexo
bool isConvex(vector<point> p) {
    bool hasPos = false, hasNeg = false;
    for (int i = 0, n = p.size(); i < n; i++) {
        int o = orientation(p[i], p[(i+1)%n], p[(i+2)%n]);
        if (o > 0) hasPos = true;
        if (o < 0) hasNeg = true;
    }
    return !(hasPos && hasNeg);
}


bool half(point p) { // true if in blue half
    assert(p.x != 0 || p.y != 0); // the argument of (0,0) isundefined
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

//ordena os pontos de acordo com o angulo
void polarSort(vector<point> &v) {
    sort(v.begin(), v.end(), [](point v, point w) { 
        return make_tuple(half(v), 0, sq(v)) < 
        make_tuple(half(w), (v^w), sq(w));
    });
}

//rotaciona o vetor 90 graus
point rotate90(point p) {
	return point(-p.y, p.x);
}

//retorna uma linha perpendicular a linha s que passa pelo ponto p
line perpointhrough(line s, point p){
    return {p, p + (rotate90(s.p - s.q))};//pode alterar a ordem
}

// se p pertence ao seg de r
bool isinseg (line r, point p) { 
	point a = r.p - p, b = r.q - p;
	return (a ^ b) == 0 and (a * b) <= 0;
}

bool intersect(line r, line s){
    int o1 = orientation(r.p, r.q, s.p);
    int o2 = orientation(r.p, r.q, s.q);
    int o3 = orientation(s.p, s.q, r.p);
    int o4 = orientation(s.p, s.q, r.q);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && isinseg(r, s.p)) return true;
    if (o2 == 0 && isinseg(r, s.q)) return true;
    if (o3 == 0 && isinseg(s, r.p)) return true;
    if (o4 == 0 && isinseg(s, r.q)) return true;

    return false;
}

// numero de pontos inteiros no segmento
int segpoints(line r) { 
	return 1 + gcd(abs(r.p.x - r.q.x), abs(r.p.y - r.q.y));
}

int polarea2(vector<point> v){ // 2 * area do poligono
	int ret = 0;
	for (int i = 0; i < v.size(); i++){
		ret += sarea2(point(0, 0), v[i], v[(i + 1) % v.size()]);
    }
    return abs(ret);
}

// se o ponto ta dentro do poligono: retorna 0 se ta fora,
// 1 se ta no interior e 2 se ta na borda
int inpol(vector<point>& v, point p){ // O(n)
	int qt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (p == v[i]) return 2;
		int j = (i+1)%v.size();
		if (p.y == v[i].y and p.y == v[j].y) {
			if ((v[i]-p)*(v[j]-p) <= 0) return 2;
			continue;
		}
		bool baixo = v[i].y < p.y;
		if (baixo == (v[j].y < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (!t) return 2;
		if (baixo == (t > 0)) qt += baixo ? 1 : -1;
	}
	return qt != 0;
}

// Closest pair of points
//
// O(nlogn)
int closest_pair_of_points(vector<point> v) {
	int n = v.size();
	sort(v.begin(), v.end());//sort nos pontos pelo x
    debug(v);
	for (int i = 1; i < n; i++) if (v[i] == v[i-1]) return 0;
	auto cmp_y = [&](const point &l, const point &r) {
		if (l.y != r.y) return l.y < r.y;
		return l.x < r.x;
	};
	set<point, decltype(cmp_y)> s(cmp_y); //set que ordena pelo y
	int l = 0, r = -1;//range do vetor atualmente no set
	int d2_min = numeric_limits<int>::max();
	point pl, pr;
    const int magic = 5;
    //por prova matematica, so precisa checar no maximo 5/6 vizinhos para encontrar um par com distancia melhor que d2min
	while (r+1 < n) {
		auto it = s.insert(v[++r]).first;//insere os pontos por ordem do x
		int cnt = magic/2;
		while (cnt-- and it != s.begin()) it--;//vai no maximo 2 pra esquerda dentro do set
		cnt = 0;
		while (cnt++ < magic and it != s.end()) {//vai no maximo 5 (a partir da esquerda) pra direita dentro do set
			if (!((*it) == v[r])) {
				int d2 = dist2(*it, v[r]);//compara todos os 5 pontos com o ultimo ponto inserido
				if (d2_min > d2) {
					d2_min = d2;
					pl = *it;
					pr = v[r];
				}
			}
			it++;
		}
		while (l < r and sq(v[l].x-v[r].x) > d2_min) s.erase(v[l++]);
        //se o dx entre p.r e p.l for maior que a dist minima ja encontrada, entao remove do set
        //pq e garantido q a distancia entre os proximos r a serem inseridos terao uma distancia maior
        debug(s);
	}
	return d2_min;
}

//

signed main(){
    winton;
    int n;
    cin >> n;
    vector<point> a(n);
    for (auto &u : a){
        cin >> u;
    } 
    int ans = closest_pair_of_points(a);
    cout << ans << endl;
}