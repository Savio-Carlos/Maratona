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
    ostream& operator<<(ostream& os, const pair<T1, T2>& p);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

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

const int MAX = 1e6+7;

struct BIT{
    vector<int> bit;
    int n;
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }

    int sum(int x){
        int s = 0;
        for(; x > 0; x -= x&(-x)){
            s += bit[x];
        }
        return s;
    }

    int query(int l, int r) { 
		return sum(r) - sum(l - 1); 
	}

    void upd(int x, int v){
        for(; x <= n; x += x&(-x)){
            bit[x] += v;
        }
    }
};

signed main(){
    winton;
    int n, q;
    cin >> n >> q;
    vector<int> points;//todos os pontos R tanto das queries quanto dos intervalos
    map<int, vector<int>> ends;
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        points.push_back(r);
        ends[r].push_back(l);
    }
    map<int, vector<pair<int,int>>> queries;
    // R, {L, idx da query}
    vector<int> ans(q,0);

    for (int qq = 0; qq < q; qq++){
        int m;
        cin >> m;
        vector<int> pts;
        pts.push_back(0);
        pts.push_back(MAX);
        for (int i = 0; i < m; i++){
            int x;
            cin >> x;
            pts.push_back(x);
            points.push_back(x);
        }
        sort(all(pts));
        for (int i = 1; i < pts.size(); i++){
            queries[pts[i]].emplace_back(pts[i-1], qq);
        }
    }
    points.push_back(MAX);
    sort(all(points));
    points.erase(unique(points.begin(), points.end()), points.end());
    debug(points);
    debug(queries);

    BIT bit;
    bit.init(MAX);

    for (int i = 0; i < points.size(); i++){
        //a insercao do ponto L do intervalo acontece depois da query 
        int r = points[i];

        for (auto [l, qidx] : queries[r]){
            ans[qidx] += bit.query(l+1, r);
        }

        for (auto l : ends[r]){
            bit.upd(l, 1);
        }
    }

    for (auto u : ans) cout << n - u << endl;
}

/*
fazer todas as queries points[i], points[i+1] na bit
sempre que eu chegar num r eu olho para todos os intervalos que fecham ali e adiciono no ponto L do intervalo na bit
respondo offline
vou iterando pelos pontos r's dos intervalos, porem tenho que reponder as queries tambem

*/