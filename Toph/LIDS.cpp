#include <bits/stdc++.h>
#include <bit>
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


pair<int,int> dp[20][11][2];
bool visited[20][11][2];
int n, k;

vector<int> v; 
vector<int> v2; 

pair<int,int> pd(int index, int above, int under, int last, int ldz){
    if (index == -1){
        return {0LL, 1LL};
    } 
    
    if (!above && !under && visited[index][last][ldz]) return dp[index][last][ldz];

    int ub = above ? v[index] : 9;
    int lb = under ? v2[index] : 0;
    int ans = 0;
    int ways = 0;

    for (int digit = lb; digit <= ub; digit++){
        int new_above = above && (digit == ub);
        int new_under = under && (digit == lb);

        int new_ldz = ldz && (digit == 0);
        
        int next = new_ldz ? 10 : digit;    
        
        auto [best, bways] = pd(index - 1, new_above, new_under, last, new_ldz);


        if (!new_ldz && ((digit > last) || (last == 10))){
            auto [b2, w2] = pd(index - 1, new_above, new_under, next, new_ldz);

            b2++;
            if (b2 > best){
                best = b2;
                bways = w2;
            }
            else if (b2 == best) bways += w2;

        } 

        debug(index, last, digit, best, bways);

        if (best > ans){
            ans = best;
            ways = bways;
        }
        else if(best == ans) ways += bways;
    }
    
    if (!above && !under) {
        dp[index][last][ldz] = {ans,ways}; 
        visited[index][last][ldz] = 1;
    }
    return {ans,ways};
}

pair<int,int> count(int x, int y){
    v2.clear();
    while(x) {
        v2.push_back(x % 10);
        x /= 10;
    }
    v.clear();

    while(y) {
        v.push_back(y % 10);
        y /= 10;
    }
    while(v2.size() < v.size()) v2.push_back(0LL);
    debug(v2,v);

    n = v.size();
    return pd(n-1,1,1,10,1);
}

void solve(){
    int l, r;
    cin >> l >> r;
    auto [mx, ways] = count(l,r); 
  
    cout << mx << " " << ways << endl;
}

signed main(){
    winton;
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
}
