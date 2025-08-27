#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) ((int)a.size())
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

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;
const int K = 70;
/*
EV (sum of lengths) = sum of EV of lenghts
*/

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

ld fastExpo(ld base, int exp) {
    ld res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

struct pt {
    int x, y;
};

int pvet(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<pt> points(n);
    for (auto &[x,y] : points) cin >> x >> y;

    ld ans = 0, nn = 0;
    if (n < K) nn = fastExpo(2.0, n) - 1.0 - n - ((ld)n * (n - 1) / 2.0);

    for (int k = 1; k < n && k < K; k++){
        int sum = 0;
        int g = 0;
        for (int i = 0; i < n; i++){
            pt a = points[i];
            pt b = points[(i+k)%n];
        
            sum += pvet(a,b);

            int dx = abs(b.x - a.x);
            int dy = abs(b.y - a.y);
            
            g += gcd(dx, dy);
            debug(sum, g);
        }
        ld p = 0;
        if (n >= K) p = 1.0 / fastExpo(2.0, (k + 1));
        else p = (fastExpo(2.0, (n - k - 1)) - 1.0) / nn;

        ans += (ld)(sum - g) / 2.0 * p;
    }
    cout << fixed << setprecision(9) << ans+1.0 << endl;
}