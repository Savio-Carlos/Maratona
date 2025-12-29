#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
// #define int long long
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
};

int sarea2(pt p, pt q, pt r) { 
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) { 
	return sarea2(p, q, r) == 0;
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<pt> pts(n);
    for (auto &[x, y] : pts) cin >> x >> y;


    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, n-1);

    for (int i = 0; i < 30; i++){
        int a = dist(rng) % n;
        int b = dist(rng) % n;
        while (a == b) b = dist(rng) % n; 
        int cnt = 0;
        vector<pt> rem1;
        for (auto p : pts){
            if (col(pts[a], pts[b], p)) cnt++;
            else rem1.push_back(p);
        }
        if (cnt < n/3) continue;
        if (rem1.size() <= 3){
            cout << "possible\n";
            debug(rem1);    
            return 0;
        }

        a = dist(rng) % rem1.size();
        b = dist(rng) % rem1.size();
        while (a == b) b = dist(rng) % rem1.size(); 

        cnt = 0;
        vector<pt> rem2;
        for (auto p : rem1){
            if (col(rem1[a], rem1[b], p)) cnt++;
            else rem2.push_back(p);
        }
        if (cnt < rem1.size()/2) continue;
        if (rem2.size() <= 3){
            debug(rem2);
            cout << "possible\n";
            return 0;
        }


        a = dist(rng) % rem2.size();
        b = dist(rng) % rem2.size();
        while (a == b) b = dist(rng) % rem2.size(); 
        cnt = 0;
        vector<pt> rem3;
        for (auto p : rem2){
            if (col(rem2[a], rem2[b], p)) cnt++;
            else rem3.push_back(p);
        }
        if (!rem3.size()){
            cout << "possible\n";
            return 0;
        } 
    }
    cout << "impossible\n";
}