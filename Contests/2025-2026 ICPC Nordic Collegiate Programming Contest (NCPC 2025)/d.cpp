#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sq(x) ((x)*(ld)(x))

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct pt{
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_){}
    bool operator < (const pt p) const {
        if( x != p.x) return x < p.x;
        return y < p.y;
    }
    pt operator + (const pt p) const {return pt(x+p.x, y + p.y);}
    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }
    friend ostream& operator << (ostream& out, pt& p){
        return out << p.x << " " << p.y;
    }
};


ld dist2(pt p, pt q){
    return sq(p.x - q.x) + sq(p.y - q.y);
}

ld dist(pt p, pt q){
    return sqrt((ld)dist2(p, q));
}

signed main(){
    fastio;
    int n; cin >> n;
    vector<pt> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ld mx = 0;
    int canto = -1;
    for(int i = 1; i < n; i++){
        ld v = dist2(arr[0], arr[i]);
        if(v > mx){
            mx = v;
            canto = i;
        }
    }
    //cout << canto << " " << arr[canto].x << " " << arr[canto].y << endl;
    ld ans = 0;
    ld ans2 = 0.0;
    //dist, idx
    vector<pair<ld, pt>> v; 
    for(int i = 0; i < n; i++){
        ld k = dist(arr[canto], arr[i]);
        ans2 += k;
        v.push_back({k, arr[i]});
    }

    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++){
        // ld v = dist(v[i].second, v[i-1].second);
        // cout << "p " << v[i-1] << " q " << v[i] << " res: " << v << endl;
        ans += dist(v[i].second, v[i-1].second);
    }
    
    cout <<fixed << setprecision(16) << ans << endl;
}