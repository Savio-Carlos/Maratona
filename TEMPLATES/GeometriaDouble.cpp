typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

// retorna t tal que t*v pertence a reta r
double get_t(point a, line r) { 
	return (r.p^r.q) / (double) ((r.p-r.q)^a);
}

//The orthogonal projection of a point P on a line R is the point on R that is closest to P 
point<double> proj(line r, point p) {
    point v = r.q - r.p;
    point u = p - r.p;
    double k = (double)(u * v) / (double)sq(v);
    return point<double>(r.p) + (point<double>(v) * k);
}

//dist double de dois pontos
double dist(point p, point q){
    return sqrt(sq(p.x - q.x) + sq(p.y - q.y));
}

//dist entre uma linha e um ponto
double linedist(line s, point r){
    point p = s.p;
    point q = s.q;
    return ((p-r) ^ (q-r))/dist(p,q);
}
