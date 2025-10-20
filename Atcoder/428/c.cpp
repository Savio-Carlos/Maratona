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

const int MAX = 1e6;

int abre[MAX], fecha[MAX], s[MAX];

signed main(){
    winton;
    int q;
    cin >> q;
    int i = -1;

    int valid = -1;
    while (q--){
        int x;
        cin >> x;
        if (x == 1){
            i++;
            char c;
            cin >> c;
            if (c == '('){
                abre[i]++;
                s[i] = 1;
            }
            else {
                fecha[i]++;
                s[i] = 2;
            }
            if (i){
                fecha[i] = fecha[i-1] + (s[i] == 2 ? 1 : 0);
                abre[i] = abre[i-1] + (s[i] == 1 ? 1 : 0);
            }
        }
        else {
            if (s[i] == 1){
                abre[i]--;
            }
            else {
                fecha[i]--;
            }
            s[i] = 0;
            i--;
            if (i){
                fecha[i] = fecha[i-1] + (s[i] == 2 ? 1 : 0);
                abre[i] = abre[i-1] + (s[i] == 1 ? 1 : 0);
            }
            if (valid >= i && abre[i] >= fecha[i]) valid = -1;
        }
        if (fecha[i] > abre[i] && valid == -1) valid = i;

        int diff = abre[i] - fecha[i];

        if ((valid == -1 && diff == 0 ) || i == -1) cout << "Yes\n";
        else cout << "No\n";

        // for (int j = 0; j <= i; j++){
        //     cout << abre[j] << " ";
        // }cout << endl;
        
        // for (int j = 0; j <= i; j++){
        //     cout << fecha[j] << " ";
        // }cout << endl;

        // for (int j = 0; j <= i; j++){
        //     if (s[j] == 1)cout << '(' ;
        //     else cout << ')';
        // }cout << endl;
        debug(valid);
        // cout << endl;
    }
}