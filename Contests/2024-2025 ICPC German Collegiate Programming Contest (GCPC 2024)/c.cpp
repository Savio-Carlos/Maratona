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

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


signed main () {
    winton;
    int n;
    cin >> n;
    vector<string> reference;
    vector<vector<string>> pfx;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        reference.push_back(s);
    }
    for (int i = 0; i < n; i++){
        vector<string> cur;
        map<string, int> last;
        for (int j = i; j < n; j++){
            auto s = reference[j];
            if (s.size() == 1){
                char c = s[0];
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                    string o = s;
                    if (last.find(s) != last.end()) s = to_string(j - last[s]);
                    else s = "0";
                    last[o] = j;
                }
            }
            cur.push_back(s);
        }
        pfx.push_back(cur);
    }
    sort(all(pfx));
    debug(reference);
    debug(pfx);
    int q;
    cin >> q;
    while(q--){
        int m;
        cin >> m;
        vector<string> query;
        map<string, int> last;
        for (int i = 0; i < m; i++){
            string s;
            cin >> s;
            if (s.size() == 1){
                char c = s[0];
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                    string o = s;
                    if (last.find(s) != last.end()) s = to_string(i - last[s]);
                    else s = "0";
                    last[o] = i;
                }
            }
            query.push_back(s);
        }
        debug(query);
        auto it = lower_bound(pfx.begin(), pfx.end(), query);
        if (it == pfx.end()) {
            cout << "no\n";
            continue;
        }
        vector<string> res = *it;
        debug(res);
        bool match = true;
        for (int i = 0; i < m && i < res.size(); i++){
            if (res[i] != query[i]) match = false;
        }
        if (match && res.size() >= query.size()) cout << "yes\n";
        else cout << "no\n"; 
    }
}