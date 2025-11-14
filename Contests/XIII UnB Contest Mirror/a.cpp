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

const int MOD = 998244353;

int fastExpo(int base, int exp) {
    int res = 1;
    base%=MOD;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    int tot = (fastExpo(26LL,  n-m) * ((n-m+1) % MOD)) % MOD;
    debug(tot);
}

/*
numero de combinacoes total: (26^(n-m)) * (n-m+1)
XXXababa
XXababaX
XababaXX
ababaXXX

Two races are considered different if, in some lap i, the winner of that lap i is different between the races.

XXababaX
ababaXXX

Both can be abababab or abababac
So we have to reduce these common possible races
every time a letter appears in a position it could reappear again we can reduce 1
lets say we have abcde instead
XXXabcde
XXabcdeX
XabcdeXX
abcdeXXX

in this case there can never be an equal race

but if we had aba

XXabaXX
abaXXXX

these can be the same
every time there's space for a letter from the original string to reappear we have to reduce 1
this will happen when 


X X X a b c d a b c d X X X X
X X X X X X X a b c d a b c d

kmp
00001234


*/