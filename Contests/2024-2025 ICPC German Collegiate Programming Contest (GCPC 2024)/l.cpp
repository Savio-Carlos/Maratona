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

const int INF = 1e18;

int calc(int a, int b, int c, int ab, int bc, int ac, int abc, int k){
    int ans = 0;
    int cntA = (a + k - 1) / k;
    int cntB = (b + k - 1) / k;
    int cntC = (c + k - 1) / k;

    ans += cntA + cntB + cntC;
    int remA = cntA*k - a;
    int remB = cntB*k - b;
    int remC = cntC*k - c;
    //restante livre em cada letra

    //preencher bc em c
    int needC = min(remC, bc);
    remC -= needC;
    bc -= needC;

    //preencher bc em b
    int needB = min(remB, bc);
    remB -= needB;
    bc -= needB;

    //se ainda tem bc preciso passar para B
    if(bc > 0) {
        int cntBC = (bc + k - 1) / k;
        ans += cntBC;
        remB += cntBC * k - bc; 
        bc = 0; // bc foi todo processado
    }

    //preencher c e b com abc
    int needABC = min(abc, remC);
    abc -= needABC;
    remC -= needABC;
    
    //o que sobrou vai pra B
    int needABC2 = min(abc, remB);
    abc -= needABC2;
    remB -= needABC2;

    //preenchendo c com ac
    int needAC = min(ac, remC);
    ac -= needAC;
    remC -= needAC;
    
    //preenchendo b com ab
    int needAB = min(ab, remB);
    ab -= needAB;
    remB -= needAB;
    
    //pega o que soborou e que TEM que ir pra A
    int left = ab + ac + abc;
    int needA = min(left, remA);
    remA -= needA;
    left -= needA;
    ans += (left + k - 1) / k;

    debug(ans, remA, remB, remC, left);
    return ans;
}


void solve(){
    int k;
    cin >> k;
    int a, b, c, ab, ac, bc, abc;
    cin >> a >> b >> c >> ab >> bc >> ac >> abc;

    int best = INF;

    best = min({best,
        calc(a,b,c,ab,bc,ac,abc,k), 
        calc(a,c,b,ac,bc,ab,abc,k), 
        calc(b,a,c,ab,ac,bc,abc,k), 
        calc(b,c,a,bc,ac,ab,abc,k), 
        calc(c,a,b,ac,ab,bc,abc,k), 
        calc(c,b,a,bc,ab,ac,abc,k)
    });
 
    debug(best);
    cout << best << endl;
}
signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}