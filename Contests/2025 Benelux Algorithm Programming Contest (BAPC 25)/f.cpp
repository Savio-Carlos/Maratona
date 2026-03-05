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

const int MOD = 31;

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}
int modiv(int a, int b){
    return (((a % MOD )* (fastExpo(b, MOD-2) % MOD)) % MOD);
}

signed main(){
    winton;


    map<pair<int,int>, int> mp;
    for (int i = 0; i <= 30; i++){
        for (int j = 0; j <= 30; j++){
            int id = i*MOD + j + 1;
            int x = ((id-1)/MOD);
            int y = ((id-1)%MOD);
            mp[{x,y}] = id;
        }
    }


    string s;
    cin >> s;

    if (s == "send"){
        int id;
        cin >> id;
        int m = (id-1)/MOD;
        int c = (id-1)%MOD;
        debug(m,c);
        for (int x = 1; x <= 30; x++){
            int y = ((m*x) + c) % MOD;
            cout << mp[{x,y}] << " ";
        }
        cout << endl;
    }
    else {
        int a, b;
        cin >> a >> b;
        pair<int,int> p1 = {(a-1)/MOD, (a-1)%MOD};
        pair<int,int> p2 = {(b-1)/MOD, (b-1)%MOD};
        auto [x1,y1] = p1;
        auto [x2,y2] = p2;
        debug(p1,p2);

        int cima = (((y2-y1) % MOD) + MOD) % MOD;
        int baixo = (((x2-x1) % MOD) + MOD) % MOD;

        int m = modiv(cima,baixo);
        int c = (((y1 - m * x1) % MOD) + MOD) % MOD;
        cout << mp[{m,c}] << endl;
    }
}
