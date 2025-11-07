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

const int INF = LLONG_MAX;

void solve(){
    int n, kmax;
    cin >> n >> kmax;
    string s, t;
    cin >> s >> t;
    if (s == t){
        cout << 0 << endl;
        return;
    }
    int k = kmax;
    map<char, vector<int>> occ;
    for (int i = 0; i < n; i++){
        occ[s[i]].push_back(i);
    }

    vector<vector<int>> next (n, vector<int> (26));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 26; j++){
            auto it = lower_bound(occ[j + 'a'].begin(), occ[j + 'a'].end(), i);
            int x = 0;
            if (it == occ[j + 'a'].end()) x = -1;
            else x = *it;
            // debug(x);
            next[i][j] = x;
        }
    }
    // debug(next);

    int fk = -1;
    vector<int> pk;
    for (int k = 1; k <= kmax; k++){
        if (fk != -1) break;
        bool falhou = false;
        vector<int> p(n, 0);

        for (int j = 0; j < n; j++){
            int pmin = max(0LL, j - k);
            if (j) pmin = max(pmin, p[j-1]);
            int pmax = j;

            int pos = next[pmin][t[j] - 'a'] ;
            // debug(pos);     
            if (pos == -1 || pos > pmax){
                falhou = true;  
                break;
            } 
            p[j] = pos;
        }
        // debug(p);
        if (!falhou){
            pk = p;
            fk = k;
        } 
    }
    debug(fk, pk);
    if (fk == -1){
        cout << "-1\n";
        return;
    }
    vector<vector<int>> ans(fk);
    ans[fk-1] = pk;
    for (int i = fk-2; i >= 0; i--){
        vector<int> cur;
        auto prox = ans[i+1];
        for (int j = 0; j < n; j++){
            if (prox[j] == j) cur.push_back(prox[j]);
            else cur.push_back(prox[j]+1);
        }
        ans[i] = cur;
    }
    debug(ans);
    cout << fk << endl;
    for (int i = 0; i < fk; i++){
        string si = "";
        for (int j = 0; j < n; j++){
            si += s[ans[i][j]];
        }
        cout << si << endl;
    }
}

signed main () {
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}