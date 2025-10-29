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

const int INF = 1e18;

int calc(int a, int b, int c, int ab, int bc, int ac, int abc, int k){
    a += ab;
    c += ac;
    c += bc;
    int aux = min(c%k, bc);
    c -= aux;
    b += aux;
    int ans = 0;
    int aux2 = min((a + abc)%k, abc);
    a = a + abc - aux2;
    abc = aux2;

    int aux3 =  min(abc, (b + abc)%k);
    b = b + abc - aux3;
    abc = aux3;

    c += abc;


    ans += a/k + ((a%k) ? 1 : 0);
    ans += b/k + ((b%k) ? 1 : 0);
    ans += c/k + ((c%k) ? 1 : 0);
    debug(a,b,c,ab,ac,bc,abc,ans);
    return ans;
}

void solve(){
    int k;
    cin >> k;
    int a, b, c, ab, ac, bc, abc;
    cin >> a >> b >> c >> ab >> bc >> ac >> abc;
    int ans = 0;
    ans += a/k + b/k + c/k;
    a = a%k;
    b = b%k;
    c = c%k;
    debug(ans);
    int best = INF;
    //caso base acoplar ab em a
    best = min(best, calc(a,b,c,ab,bc,ac,abc,k));

    //acoplar ac em a
    best = min(best, calc(a,c,b,ac,bc,ab,abc,k));

    //acoplar ab em b
    best = min(best, calc(b,a,c,ab,ac,bc,abc,k));

    //acoplar bc em b
    best = min(best, calc(b,c,a,bc,ab,ac,abc,k));

    //acoplar ac em c
    best = min(best, calc(c,a,b,ac,ab,bc,abc,k));

    //acoplar bc em c
    best = min(best, calc(c,b,a,bc,ac,ab,abc,k));

    debug(best);
    cout << ans + best << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}