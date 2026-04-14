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

pair<int, string> dp[25][2][2][2]; // [index][above][under][ldz]
bool visited[25][2][2][2];

int n;
string l, r;

pair<int, string> pd(int index, int above, int under, int ldz){
    if(index == n) return {1, ""};
    
    if (visited[index][above][under][ldz]) return dp[index][above][under][ldz];

    int ub = above ? r[index] - '0' : 9;
    int lb = under ? l[index] - '0' : 0;
    
    int max_prod = -1;
    string best_str = "";

    for (int digit = lb; digit <= ub; digit++){

        int new_above = above && (digit == ub);
        int new_under = under && (digit == lb);
        int new_ldz = ldz && (digit == 0);

        auto [resn, ress] = pd(index + 1, new_above, new_under, new_ldz);
        
        int cur_prod = new_ldz ? resn : resn * digit;

        if (cur_prod > max_prod) {
            max_prod = cur_prod;
            if (new_ldz) best_str = ress;
            else best_str = to_string(digit) + ress;
        }
    }
    
    visited[index][above][under][ldz] = true;
    return dp[index][above][under][ldz] = {max_prod, best_str}; 
}

signed main(){
    winton;
    memset(visited, false, sizeof(visited));
    cin >> l >> r;
    n = r.size();
    if (l.size() < r.size()){
        int diff = r.size() - l.size();
        string temp(diff, '0');
        l = temp + l;
    }
    
    auto [_,ans] = pd(0, 1, 1, 1);
    cout << ans << endl;
}