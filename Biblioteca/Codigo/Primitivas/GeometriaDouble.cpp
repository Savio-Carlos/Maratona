//Geometria Double

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return fabs(a - b) <= eps;
}

struct point { // ponto
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

struct line { // reta
	point p, q;
	line() {}
	line(point p_, point q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

ld dist(point p, point q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld dist2(point p, point q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ld norm(point v) { // norma do vetor
	return dist(point(0, 0), v);
}

ld angle(point v) { // angulo do vetor com o eixo x
	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

ld sarea(point p, point q, point r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(point p, point q, point r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

bool ccw(point p, point q, point r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

point rotate(point p, ld th) { // rotaciona o ponto th radianos
	return point(p.x * cos(th) - p.y * sin(th), p.x * sin(th) + p.y * cos(th));
}

point rotate90(point p) { // rotaciona 90 graus
	return point(-p.y, p.x);
}

// retorna t tal que t*v pertence a reta r
ld get_t(point a, line r) {
	return (r.p^r.q) / ((r.p-r.q)^a);
}

bool isvert(line r) { // se r eh vertical
	return eq(r.p.x, r.q.x);
}

point proj(point p, line r) { // projecao do ponto p na reta r
	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	point proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

bool isinseg(point p, line r) { // se p pertence ao seg de r
    point a = r.p - p, b = r.q - p;
    return eq((a ^ b), 0) and (a * b) < eps;
}

point inter(line r, line s) { // r inter s
	if (eq((r.p - r.q) ^ (s.p - s.q), 0)) return point(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s) or isinseg(s.p, r) or isinseg(s.q, r)) return 1;
	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

ld linepoint(point p, line r) { // distancia do ponto a reta
	return 2 * abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
}

ld segpoint(line r, point p) { // distancia do ponto ao seg
	if ((r.q - r.p)*(p - r.p) < 0) return dist(r.p, p);
	if ((r.p - r.q)*(p - r.q) < 0) return dist(r.q, p);
	return linepoint(p, r);
}

ld segseg(point a, point b, point c, point d) {
	line ab(a,b);
	line cd(c,d);
    if (interseg(ab, cd)) return 0;
	return min({segpoint(ab,c), segpoint(ab,d), segpoint(cd,a), segpoint(cd,b)});
}

//angulo interno entre duas linhas, mid e o ponto de intersecao entre elas
ld inner_angle(point p, point q, point mid){
    point p1 = (p-mid);
    point p2 = (q-mid);
    ld rad = atan2(abs(p1 ^ p2), p1 * p2);//angulo em rad
    ld deg = rad* 180.0 / M_PI;
    return deg;
}

//linha que corta o segmento AB no meio perpendicularmente
line mediatriz(point p, point q) {
    point mid = (p + q) / 2.0;
    point vec = q - p;
    point p_vec = rotate90(vec);
    return line(mid, mid + p_vec);
}

//bissetriz interna e externa
//bissetriz = linha que forma angulos iguais com outras duas linhas
pair<line, line> bissetriz(line r, line s) {
    if (eq((r.p - r.q) ^ (s.p - s.q), 0)) return {};
	point i = inter(r,s);
	point v1 = r.p - i;
    point v2 = s.p - i;
	if (norm(v1) < eps) v1 = r.q - i;
    if (norm(v2) < eps) v2 = s.q - i;
    v1 = v1 / norm(v1); v2 = v2 / norm(v2);
    line interna = line(i, i + (v1 + v2));
    line externa = line(i, i + (v1 - v2));
    return {interna, externa};
}

point findcircle(point p, point q, point r){//acha o centro do circulo que encosta nos 3 pontos
	if (col(p,q,r)) return point(DINF,DINF);
	line mid1 = mediatriz(p,q);
	line mid2 = mediatriz(q,r);
	return inter(mid1, mid2);
}

ld polarea(vector<point> v){ // area do poligono
	ld ret = 0;
	for (int i = 0; i < v.size(); i++){
		ret += sarea(point(0, 0), v[i], v[(i + 1) % v.size()]);
	}
	return abs(ret);
}

// se o ponto ta dentro do poligono: retorna 0 se ta fora,
// 1 se ta no interior e 2 se ta na borda
int inpol(vector<point>& v, point p) { // O(n)
	int qt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (p == v[i]) return 2;
		int j = (i+1)%v.size();
		if (eq(p.y, v[i].y) and eq(p.y, v[j].y)) {
			if ((v[i]-p)*(v[j]-p) < eps) return 2;
			continue;
		}
		bool baixo = v[i].y+eps < p.y;
		if (baixo == (v[j].y+eps < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (eq(t, 0)) return 2;
		if (baixo == (t > eps)) qt += baixo ? 1 : -1;
	}
	return qt != 0;
}

ld angle(const point &p, const point &ref) { // angulo do ponto p em relacao ao ponto ref
    point v = p - ref;
    ld ang = atan2(v.y, v.x);
    if (ang < 0) ang += 2*pi;
    return ang;
}

//ordena os pontos de acordo com o angulo
void polarSort(vector<point> &v, point &ref) {
    sort(v.begin(), v.end(), [&ref](point a, point b) {
        return angle(a, ref) < angle(b, ref);
    });
}

vector<point> convex_hull(vector<point> v) { // convex hull - O(n log(n))
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (v.size() <= 1) return v;
	vector<point> l, u;
	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i]))
			l.pop_back();
		l.push_back(v[i]);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i]))
			u.pop_back();
		u.push_back(v[i]);
	}
	l.pop_back(); u.pop_back();
	for (point i : u) l.push_back(i);
	return l;
}

//comprimento do arco dado o raio e o angulo
//double comprimento = (graus * M_PI * raio) / 180.0;
//double comprimento = rad * raio;
