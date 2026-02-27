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


vector<int> factor(int n) {
    if (n == 1) return {1};
    vector<int> primes;
    for (int p = 2; p * p <= n; ++p) {
        while (n % p == 0) {
            primes.push_back(p);
            n /= p;
        }
    }
    if (n > 1) 
        primes.push_back(n);
    return primes;
}

const int MAX = 1e6+7;
int spf[MAX + 1];

void build(){
    for (int i = 2; i <= MAX; i+=2) spf[i] = 2;
    for (int i = 3; i <= MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i < MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

int menor(int x) {
    if (x <= 1) return 1;
    return spf[x];
}

bool fator(int x) {
    if (x <= 1) return true;
    int p = spf[x];
    while (x % p == 0) x /= p;
    return x == 1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    bool inc = true;
    for (int i = 1; i < n; i++){
        if (a[i-1] > a[i]) inc = false; 
    }
    if (inc){
        cout << "Bob" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!fator(a[i])) {
            cout << "Alice" << endl;
            return;
        }
    }

    bool win = true;
    for (int i = 1; i < n; i++) {
        if (menor(a[i-1]) > menor(a[i])) {
            win = false;
            break;
        }
    }
    if (!win) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

signed main(){
    winton;
    build();
    int t;
    cin >> t;
    while(t--) solve();
}