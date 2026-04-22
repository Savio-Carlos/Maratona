#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

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

int sarea2(pt p, pt q, pt r) { 
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<pt> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i];
    
    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }
    
    vector<int> linhas_mask;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int mask = 0;
            for (int k = 0; k < n; k++) {
                if (col(pts[i], pts[j], pts[k])) {
                    mask |= (1LL << k);
                }
            }
            linhas_mask.push_back(mask);
        }
    }
    
    sort(all(linhas_mask));
    linhas_mask.erase(unique(all(linhas_mask)), linhas_mask.end());
    
    int todos = (1 << n) - 1;
    vector<int> dp(todos + 1, 20);
    dp[0] = 0;

    for (int mask = 0; mask < todos; mask++) {
        if (dp[mask] == 1e9) continue;
        
        for (auto line_mask : linhas_mask) {
            int nxt = mask | line_mask;
            dp[nxt] = min(dp[nxt], dp[mask] + 1);
        }
    }

    cout << dp[todos] << endl;
}