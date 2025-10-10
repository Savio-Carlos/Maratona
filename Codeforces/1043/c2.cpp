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

/*
e se eu ir relaxando a quantidade de deals
eu quero 3 melancias, com k = 3
eu posso fazer garantidamente com 1 deal
mas ai eu vejo que se eu tirar esse deal eu posso usar 3 deals de 1 melancia
entao eu vejo o maior e tento reduzir ele
fazer vetor de frequenia pra cada potencia de 3 e ao inves de remover um por um dividir e multiplicar
*/

vector<int> pot;
map<int,int> cost;

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

void build(){
    pot.push_back(1);
    cost[1] = 3;
    for (int i = 1; i < 20; i++){
        pot.push_back(fastExpo(3LL, i));
        cost[pot.back()] = (fastExpo(3LL, i+1) + (i * fastExpo(3LL, i-1)));
    }
    reverse(all(pot));
}

void solve(){
    map<int,int, greater<int>> freq;
    int n, k, ans = 0;
    cin >> n >> k;
    int cnt = 0;
        for (int i = 0; i < 20; i++){
        while (pot[i] <= n){
            n -= pot[i];
            cnt++;
            freq[pot[i]]++;
            debug(pot[i], n);
        }
    }
    debug(cnt);
    if (cnt > k) {
        cout << -1 << endl;
        return;
    }
    debug(freq);
    for (auto [p, q] : freq){
        if (p == 1) continue;
        if (cnt+2 > k) continue;
    
        int l = 0, r = q+1; 
        while (l < r){
            int mid = (l+r)/2;
            int tot = mid*3 + cnt - mid;
            debug(mid,tot);
            
            if (tot <= k){
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        int red = r-1;
        debug(p, q, red, cnt);
        
        freq[p] -= red;
        cnt-=red;
        freq[p/3] += 3*red;
        cnt += 3*red;
    }
    debug(freq);
    for (auto [p, q] : freq) ans += cost[p] * q;

    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    build();
    while(t--) solve();
}