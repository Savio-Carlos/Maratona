
struct point {
    int x, y;
    point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    bool operator == (const point p) const {
		return x == p.x and y == p.y;
	}
	point operator + (const point p) const { return point(x+p.x, y+p.y); }
	point operator - (const point p) const { return point(x-p.x, y-p.y); }
	point operator * (const int c) const { return point(x*c, y*c); }
	int operator * (const point p) const { return x*(int)p.x + y*(int)p.y; }
	int operator ^ (const point p) const { return x*(int)p.y - y*(int)p.x; }
    
    friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line {
	point p, q;
	line() {}
	line(point p_, point q_) : p(p_), q(q_) {}
    
    friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

int dot(point p, point q) {
    return p.x * q.x + p.y * q.y;
}

int cross (point p, point q){
    return p.x * q.y - p.y * q.x;
}

bool perpendicular(point v, point w){
    return (dot(v,w) == 0);
}

//ccw
int orientation(ponto p, ponto q, ponto r){
    int val = cross(q-p, r-p);
    if (!val) return 0;
    return (val > 0) ? 1 : -1;
}

//checa se um ponto esta contido no angulo do segmento pq e pr
bool onAngle (point p, point q, point r, point g){
    if (!orientation(p,q,r)) return false;
    if (orientation(p,q,r) > 0) swap(q,r);
    return orientation(p,q,g) >= 0 && orientation(p,r,g) <= 0; 
}

int sq(point p){
    return p.x*p.x + p.y*p.y;
}

double abs(point p){
    return sqrt(sq(p));
}

double pointdist(point p, point q){
    return sqrt(sq(p.x - q.x) + sq(p.y - q.y));
}

double linepointdist(line r, point p){
    return 
}
