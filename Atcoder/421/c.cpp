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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

signed main(){
    winton;
    int n;
    string s;
    cin >> n >> s;
    n*=2;
    vector<int> as, bs;
    string a = "", b = "", t = s;
    for (int i = 0; i < n; i++){
        if (s[i] == 'A') as.push_back(i);
        if (s[i] == 'B')  bs.push_back(i);
        if (i&1){
            a+= "B";
            b+= "A";
        } 
        else {
            a+= "A";
            b+= "B";
        }
    }
    debug(a);
    debug(b);
    int ans1 = 0, ans2 = 0, ai = 0, bi = 0;;
    for (int i = 0; i < n; i++){
        if (s[i] != a[i]){
            if (s[i] == 'A'){
                while (bi < sz(bs) && bs[bi] < i) bi++;
                swap(s[i], s[bs[bi]]);
                ans1 += bs[bi] - i;
                bi++;
            }
            else{
                while (ai < sz(as) && as[ai] < i) ai++;
                swap(s[i], s[as[ai]]);
                ans1 += as[ai] - i;
                ai++;
            }
            debug(s);
        }
    }
    ai = 0, bi = 0;
    for (int i = 0; i < n; i++){
            if (t[i] != b[i]){
            if (t[i] == 'A'){
                while (bi < sz(bs) && bs[bi] < i) bi++;
                swap(t[i], t[bs[bi]]);
                ans2 += bs[bi] - i;
                bi++;
            }
            else{
                while (ai < sz(as) && as[ai] < i) ai++;
                swap(t[i], t[as[ai]]);
                ans2 += as[ai] - i;
                ai++;
            }
            debug(t);
        }
    }
    

    cout << min(ans1, ans2) << endl;
}