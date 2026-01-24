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

struct DSU {
	vector<int> id, sz;

	DSU(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }
    int sizee(int a) { return sz[find(a)]; }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

signed main(){
    winton;
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> inter(n);
    vector<pair<int,int>> sorted(n);
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        sorted[i] = {k,i};
        for (int j = 0; j < k; j++){
            int x;
            cin >> x;
            inter[i].push_back(x);
        }   
    }
    DSU dsu(m+1);
    sort(all(sorted));
    int p1 = -1;
    for (auto [siz, idx] : sorted){
        if (siz <= 1) continue;

        for (int i = 0; i+1 < siz; i++){
            dsu.unite(inter[idx][i], inter[idx][i+1]);
        }
        debug(idx, siz,dsu.sz[inter[idx][0]]);
        debug(dsu.sizee(inter[idx][0]));

        if (dsu.sizee(inter[idx][0]) != siz){
            p1 = idx;
            break;
        }
    }

    if (p1 == -1){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << p1+1 << " ";
    vector<int> freq(m+1, 0);
    auto st = inter[p1];
    for (auto u : st) freq[u]++;
    for (int i = 0; i < n; i++){
        if (i == p1) continue;
        int equal = 0;
        int diff = 0;
        for (auto u : inter[i]){
            if(freq[u]) equal++;
            else diff++; 
        }
        int r = (int)st.size() - equal;

        // debug(p1, i, equal, diff, r);
        if (r > 0 && equal > 0 && diff > 0) {
            cout << i+1 << endl;
            return 0;
        }
    }
}
  