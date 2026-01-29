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

int best_disjoint(int target, int fixed){
    int maxv = max(target, fixed);
    int B = 0;
    while (B < 62 && (1LL << B) <= maxv) B++;
    if (B == 0) B = 1;
    if (B < 62) B++;
    int mask = (1LL << B) - 1;
    int allowed = (~fixed) & mask;
    long long down = 0;
    bool tight = true;
    for (int pos = B - 1; pos >= 0; --pos){
        int ab = (allowed >> pos) & 1LL;
        int tb = (target >> pos) & 1LL;
        if (!tight){
            if (ab) down |= (1LL << pos);
            continue;
        }
        if (tb == 0){
            continue;
        } else {
            if (ab) down |= (1LL << pos);
            else tight = false;
        }
    }

    long long up = 0;
    vector<int> bumps;
    for (int pos = B - 1; pos >= 0; --pos){
        int ab = (allowed >> pos) & 1LL;
        int tb = (target >> pos) & 1LL;
        if (tb == 1){
            if (!ab){
                while(!bumps.empty()){
                    int bpos = bumps.back();
                    bumps.pop_back();
                    up &= ~((1LL << (bpos + 1)) - 1);
                    up |= (1LL << bpos);
                    goto done_up;
                }
                up = LLONG_MAX;
                goto done_up;
            }
            up |= (1LL << pos);
        } else {
            if (ab) bumps.push_back(pos);
        }
    }
done_up:
    if (up == LLONG_MAX) return (int)down;
    long long diff_down = llabs(target - down);
    long long diff_up = llabs(target - up);
    if (diff_up < diff_down) return (int)up;
    return (int)down;
}

void solve(){
    int x, y;
    cin >> x >> y;
    int p = 0, q = 0;

    p = x;
    q = (int)best_disjoint(y, p);
    int ans1 = abs(x-p) + abs(y-q);
    pair<int,int> a1 = {p,q}; 
    
    q = y;
    p = (int)best_disjoint(x, q);
    int ans2 = abs(x-p) + abs(y-q);
    pair<int,int> a2 = {p,q}; 


    debug(a1,a2);
    debug(ans1,ans2);
    if (ans1 <= ans2)cout << a1.first << " " << a1.second << endl;
    else cout << a2.first << " " << a2.second << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}