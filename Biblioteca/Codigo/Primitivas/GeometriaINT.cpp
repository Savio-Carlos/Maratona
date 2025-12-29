//Geometria Int

struct pt {
    int x, y;
    pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}

	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}

    pt operator + (const pt& p) const { return pt(x + p.x, y + p.y); }
    pt operator - (const pt& p) const { return pt(x - p.x, y - p.y); }
    template<typename U>
    pt operator * (const U c) const { return pt(x * c, y * c); }
    auto operator * (const pt& p) const { return (int)x * p.x + (int)y * p.y; }
    auto operator ^ (const pt& p) const { return (int)x * p.y - (int)y * p.x; }

    friend istream& operator >> (istream& in, pt& p) { return in >> p.x >> p.y; }
    friend ostream& operator << (ostream& os, const pt& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

struct line {
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
    
    friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}

    friend ostream& operator << (ostream& os, line& r) {
		return os << "[" << r.p << " -> " << r.q << "]";
	}
};

int sq(pt p){
    return p.x*p.x + p.y*p.y;
}

int abs(pt p){
    return sqrt(sq(p));
}

//checa se dois vetores sao perpendiculares
bool perpendicular(pt v, pt w){
    return (v*w == 0);
}

//ccw, 0 colineares, -1 r a direita, 1 r a esquerda
int orientation(pt p, pt q, pt r){
    int val = ((q-p) ^ (r-p));
    if (!val) return 0;
    return (val > 0) ? 1 : -1;
}

//checa se um ponto esta contido no angulo do segmento pq e pr
bool onAngle (pt p, pt q, pt r, pt g){
    if (!orientation(p,q,r)) return false;
    if (orientation(p,q,r) > 0) swap(q,r);
    return orientation(p,q,g) >= 0 && orientation(p,r,g) <= 0; 
}

// quadrante de um ponto
int quad(pt p) { 
	return (p.x<0)^3*(p.y<0);
}

//dist quadrada de dois pontos
int dist2(pt p, pt q){
    return sq(p.x - q.x) + sq(p.y - q.y);
}

// 2 * area com sinal
int sarea2(pt p, pt q, pt r) { 
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

// 2 * area do poligono
int polarea2(vector<pt> v) { 
	int ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea2(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
}

//checa se o poligono e convexo
bool isConvex(vector<pt> p) {
    bool hasPos = false, hasNeg = false;
    for (int i = 0, n = p.size(); i < n; i++) {
        int o = orientation(p[i], p[(i+1)%n], p[(i+2)%n]);
        if (o > 0) hasPos = true;
        if (o < 0) hasNeg = true;
    }
    return !(hasPos && hasNeg);
}


bool half(pt p) { // true if in blue half
    assert(p.x != 0 || p.y != 0); // the argument of (0,0) isundefined
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

//ordena os pontos de acordo com o angulo
void polarSort(vector<pt> &v) {
    sort(v.begin(), v.end(), [](pt v, pt w) { 
        return make_tuple(half(v), 0, sq(v)) < 
        make_tuple(half(w), (v^w), sq(w));
    });
}

//rotaciona o vetor 90 graus
pt rotate90(pt p) {
	return pt(-p.y, p.x);
}

//retorna uma linha perpendicular a linha s que passa pelo ponto p
line perpthrough(line s, pt p){
    return {p, p + (rotate90(s.p - s.q))};//pode alterar a ordem
}

// se p pertence ao seg de r
bool isinseg (line r, pt p) { 
	pt a = r.p - p, b = r.q - p;
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
int segpts(line r) { 
	return 1 + gcd(abs(r.p.x - r.q.x), abs(r.p.y - r.q.y));
}

int polarea2(vector<pt> v){ // 2 * area do poligono
	int ret = 0;
	for (int i = 0; i < v.size(); i++){
		ret += sarea2(pt(0, 0), v[i], v[(i + 1) % v.size()]);
    }
    return abs(ret);
}

// se o ponto ta dentro do poligono: retorna 0 se ta fora,
// 1 se ta no interior e 2 se ta na borda
int inpol(vector<pt>& v, pt p){ // O(n)
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

int paralelos(vector<pair<int,int>> &pontos){
    int qnt = 0;
    pair<int,int> e0 = reta(pontos[0], pontos[1]);
    pair<int,int> e1 = reta(pontos[1], pontos[2]);
    pair<int,int> e2 = reta(pontos[2], pontos[3]);
    pair<int,int> e3 = reta(pontos[3], pontos[0]);
    if (cross(e0, e2) == 0) ++qnt;
    if (cross(e1, e3) == 0) ++qnt;
    return qnt;
}
 