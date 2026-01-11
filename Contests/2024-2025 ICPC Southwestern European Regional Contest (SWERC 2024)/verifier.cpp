// verifier.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P { ll x,y; };

ll cross(const P &a, const P &b, const P &c){
    // (b-a) x (c-a)
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
int sgn(ll v){ return (v>0)-(v<0); }

bool on_seg(const P &a, const P &b, const P &p){
    if (cross(a,b,p) != 0) return false;
    return min(a.x,b.x) <= p.x && p.x <= max(a.x,b.x)
        && min(a.y,b.y) <= p.y && p.y <= max(a.y,b.y);
}

bool seg_intersect_strict(const P &a, const P &b, const P &c, const P &d){
    // returns true if segments ab and cd intersect in a point other than allowed shared endpoint
    ll c1 = cross(a,b,c), c2 = cross(a,b,d);
    ll c3 = cross(c,d,a), c4 = cross(c,d,b);

    if ( (sgn(c1)*sgn(c2) < 0) && (sgn(c3)*sgn(c4) < 0) ) return true;
    // handle collinear overlap:
    if (c1==0 && on_seg(a,b,c)) return true;
    if (c2==0 && on_seg(a,b,d)) return true;
    if (c3==0 && on_seg(c,d,a)) return true;
    if (c4==0 && on_seg(c,d,b)) return true;
    return false;
}

long long gcdll(long long a, long long b){
    if (a<0) a=-a; if (b<0) b=-b;
    while(b){ long long t=a%b; a=b; b=t; } return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    vector<P> req(N);
    set<pair<ll,ll>> reqset;
    for(int i=0;i<N;i++){ cin>>req[i].x>>req[i].y; reqset.insert({req[i].x, req[i].y}); }
    int K;
    if(!(cin>>K)){ cout<<"ERROR: no polygon read (expect K)\n"; return 0; }
    if (K <= 0) { cout<<"ERROR: K <= 0\n"; return 0; }
    vector<P> poly(K);
    set<pair<ll,ll>> used;
    for(int i=0;i<K;i++){ cin>>poly[i].x>>poly[i].y; used.insert({poly[i].x,poly[i].y}); }

    // Basic checks:
    for(int i=0;i<K;i++){
        if (poly[i].x < 1 || poly[i].x > 1000000000LL || poly[i].y < 1 || poly[i].y > 1000000000LL){
            cout<<"ERROR: vertex out of bounds: "<<poly[i].x<<" "<<poly[i].y<<"\n";
            return 0;
        }
    }
    if ((int)used.size() != K){
        cout<<"ERROR: duplicate vertices in polygon\n"; return 0;
    }
    // all required points must appear among vertices
    for(auto &p : reqset){
        if (used.find(p) == used.end()){
            cout<<"ERROR: required point not present in polygon vertices: "<<p.first<<" "<<p.second<<"\n";
            return 0;
        }
    }
    if (K > 3*N){
        cout<<"ERROR: K = "<<K<<" > 3*N = "<<3*N<<"\n"; return 0;
    }

    // Check simplicity: no segment intersections except adjacent segments sharing endpoints
    auto seg = [&](int i){ return make_pair(poly[i], poly[(i+1)%K]); };
    for(int i=0;i<K;i++){
        for(int j=i+1;j<K;j++){
            // skip adjacent or same segment
            if ( (i+1)%K == j ) continue;
            if ( i == (j+1)%K ) continue;
            auto [a,b] = seg(i);
            auto [c,d] = seg(j);
            // If they intersect in any way => invalid
            if (seg_intersect_strict(a,b,c,d)){
                cout<<"ERROR: segments intersect: seg "<<i<<"("<<a.x<<","<<a.y<<")-("<<b.x<<","<<b.y<<")"
                    <<" and seg "<<j<<"("<<c.x<<","<<c.y<<")-("<<d.x<<","<<d.y<<")\n";
                return 0;
            }
        }
    }

    // Compute area2 and boundary lattice points B
    long long area2 = 0;
    long long B = 0;
    for(int i=0;i<K;i++){
        P a = poly[i], b = poly[(i+1)%K];
        area2 += a.x * b.y - a.y * b.x;
        long long dx = b.x - a.x;
        long long dy = b.y - a.y;
        B += gcdll(abs(dx), abs(dy));
    }
    if (area2 < 0) area2 = -area2;
    // Pick: area = I + B/2 - 1 => I = area - B/2 + 1
    // area2 = 2*area => I = (area2 - B + 2)/2
    if ( (area2 - B + 2) < 0 ){
        cout<<"ERROR: invalid area/boundary combination (negative interior by formula)\n"; return 0;
    }
    if ( (area2 - B + 2) % 2 != 0 ){
        cout<<"ERROR: (area2 - B + 2) not even (numerical inconsistency)\n"; return 0;
    }
    long long I = (area2 - B + 2) / 2;
    if (I != 0){
        cout<<"ERROR: polygon has "<<I<<" integer points strictly inside (must be 0)\n";
        return 0;
    }

    cout<<"OK\n";
    return 0;
}
