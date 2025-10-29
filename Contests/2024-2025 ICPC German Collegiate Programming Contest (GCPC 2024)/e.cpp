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

const int MAX = 3e2+7;

int dp[MAX][MAX][MAX][2];//1 = me, 0 = you -> na verdade vai ser se essa paridade ganha ou nao, entao 1 = sucesso 0 = fail
int n, nochange, even, change;


int pd(int nc, int c, int e, bool p){
    if (nc + e + c == n){
        if ((nc+c+e)%2 == 1) return (p == 0);
        else return (p == 1);
    }
    
    if(dp[nc][c][e][p] != -1LL) return dp[nc][c][e][p];
    
    int pos = 0;
    
    //se ele jogar uma carta de tal tipo e NAO ganhar, entao a gente ganha
    if (nc < nochange && !pd(nc+1, e, c, !p)) pos = 1;
    if (!pos && c < change && !pd(nc, c+1, e, !p)) pos = 1;
    if (!pos && e < even && !pd(nc, c, e+1, !p)) pos = 1;
    
    debug(nc, c, e, p, dp[nc][c][e][p] = pos);
    return dp[nc][c][e][p] = pos;
}

signed main () {
    winton;
    // int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++){
        char type;
        int v;
        cin >> type >> v;
        v%=2;
        if (type == '+'){
            if (v == 0) nochange++;
            else change++;
        }
        else {
            if (v == 0) even++;
            else nochange++;
        }
    }
    int x;
    cin >> x;
    debug(nochange, change, even);
    pd(0,0,0,x%2);
    debug(dp[0][0][0][0],dp[0][0][0][1]);
    int turn = -1;
    if (dp[0][0][0][x%2]){
        cout << "me\n";
        turn = 0;
    }
    else {
        cout << "you\n";
        turn = 1;
    }
    for (int i = 0; i < n; i++){
        if (!turn){

        }    
    }



}