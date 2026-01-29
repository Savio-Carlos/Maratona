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

vector<int> kmp(string s){
    int n = s.size(), pfxlen = 0;
    vector<int> a(n, 0);
    for (int i = 1; i < n; i++){
        if (s[i] == s[pfxlen]) a[i] = ++pfxlen;
        else if (pfxlen){
            pfxlen = a[pfxlen-1];
            i--;
        }
        else a[i] = 0;
    }
    return a;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1){
        cout << s << endl;
        return;
    }
    int l = 0, r = n-1;
    while(l < n/2 && r >= n/2 && s[l] == s[r]){
        l++;
        r--;
    }
    debug(l, r);
    int lim = min(l, n - r - 1);
    string comeco = s.substr(0, lim);
    string fim = comeco;
    reverse(all(fim));
    string resto = s.substr(lim, n - 2*lim);
    debug(lim, resto, comeco);
    auto rev = resto;

    reverse(all(rev));
    auto lps1 = kmp(resto + '#' + rev);
    int len1= lps1.back();
    string meio1 = resto.substr(0, len1);
    
    auto lps2 = kmp(rev + '#' + resto);
    int len2 = lps2.back();
    string meio2 = rev.substr(0, len2);
    cout << comeco << (len2 > len1 ? meio2 : meio1) << fim << endl;;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();

}
