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

const int INF = 2e18; 

struct tacada {
    int v;
    char t;
};

struct obstaculo {
    int x, y;
    char dir;
};

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<obstaculo> obs(n);
    vector<tacada> tac(m);
    for (auto &[x, y, dir] : obs) cin >> x >> y >> dir;
    for (auto &[v, t] : tac) cin >> v >> t;

    int curx = 0, cury = 0;
    char curdir;
    
    for (int i = 0; i < m; i++){
        auto [v, t] = tac[i];
        debug(v, t);
        int rem = v;
        curdir = t;
        bool stop = false;

        while (rem > 0 && !stop){
            int nextx = -INF, nexty = -INF;
            char nextid = '0';
            int d = INF;

            for (int j = 0; j < n; j++){
                auto [x, y, id] = obs[j];
                
                if (curdir == '^' && x == curx && y > cury){   
                    if (y < d + cury){
                        nexty = y; nextx = x; nextid = id;
                        d = y - cury;
                    } 
                }
                if (curdir == 'v' && x == curx && y < cury){   
                    if (cury - y < d){
                        nexty = y; nextx = x; nextid = id;
                        d = cury - y;
                    } 
                }
                if (curdir == '>' && y == cury && x > curx){   
                    if (x < d + curx){
                        nexty = y; nextx = x; nextid = id;
                        d = x - curx;
                    } 
                }
                if (curdir == '<' && y == cury && x < curx){   
                    if (curx - x < d){
                        nexty = y; nextx = x; nextid = id;
                        d = curx - x;
                    } 
                }
            }

            if (nextid != '0' && d <= rem) {

                curx = nextx;
                cury = nexty;
                rem -= d;

                if (nextid == 'o'){
                    cout << i + 1 << endl;
                    return 0;
                } else if (nextid == '#') {
                    rem = 0; 
                    stop = true;
                } 
                else curdir = nextid;
                
            } else {
                if (curdir == '^') cury += rem;
                if (curdir == 'v') cury -= rem;
                if (curdir == '>') curx += rem;
                if (curdir == '<') curx -= rem;
                rem = 0;
                stop = true;
            }
        }
    }
    cout << -1 << endl;
}