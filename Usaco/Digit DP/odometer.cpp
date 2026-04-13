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

void setIO(string name = "") {
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int dp[20][20][2][2][20]; // [index][cnt][above][under][leadingzeros]
int n;
 
int DIGITO = 5;

string l,r;

int pd(int index, int cnt, int above, int under, int ldz, int m){
    if(index == n){
        // debug(cnt, n, ldz);
        if (m) return (2*cnt >= (n-ldz));
        else return (2*cnt == (n-ldz));
    } 
 
    if (dp[index][cnt][above][under][ldz] != -1) return dp[index][cnt][above][under][ldz];
 
    int ub = above ? r[index] - '0' : 9;
    int lb = under ? l[index] - '0' : 0;

    int ans = 0;

    for (int digit = lb; digit <= ub; digit++){
 
        int new_above = above && (digit == ub);
        int new_under = under && (digit == lb);

        int new_ldz = ldz + ((digit == 0) && (ldz == index));
        
        int next = digit;
        if (next == DIGITO && !(digit == 0 && ldz == index)) ans += pd(index + 1, cnt+1, new_above, new_under, new_ldz, m);
        else ans += pd(index + 1, cnt, new_above, new_under, new_ldz, m);
    }
    return dp[index][cnt][above][under][ldz] = ans; 
 
}

signed main(){
    winton;
    // setIO("odometer");
    cin >> l >> r;
    if (l.size() < r.size()){
        int diff = r.size() - l.size();
        string temp(diff, '0');
        l = temp + l;
    }
    n = r.size();
    int ans = 0;
    for (int i = 0; i <= 9; i++){
        memset(dp,-1, sizeof(dp));
        DIGITO = i;
        ans += pd(0,0,1,1,0,1);
    }
    int dup = 0;
    for (int i = 0; i <= 9; i++){
        memset(dp,-1, sizeof(dp));
        DIGITO = i;
        dup += pd(0,0,1,1,0,0);
    }
    debug(ans, dup);
    cout << ans - (dup/2) << endl;
}

/*
count the amount of each digit up to each position of the number
dp[n][3] = 3 should mean that i can get to index N with 3 3's
but what if i can get with 4 or 2 3's as well?

de tamanho impar sempre vai ter um sobresalente (33322, 33122 nao e valido)
de tamanho impar temos (8+7+6+5+4+3+2+1)55 casos em que rola um empate - 9
10 -> inverter pra 01 entao nao rola isso
11 -> nao e recontado
12
13
14
23
34
45
89

entao para cada possibilidade de tamanho par da string tiramos 55?
para numeros de 2 digitos podemos ter xy (que e recontado como yx)
para numeros de 4 digitos podemos ter xxyy
para numeros de 6 digitos podemos ter xxxyyy
..assim por diante



*/