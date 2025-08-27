#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) ((int)a.size())
#define endl '\n'
#define int long long
#define ld long double

namespace debug_ns {
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
using namespace debug_ns;

#define DEBUG
#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
    #define vdebug(a) cerr << #a << " = ["; for(auto it = (a).begin(); it != (a).end(); ++it) cerr << *it << (std::next(it) == (a).end() ? "" : ", "); cerr << "]" << endl;
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
    #define vdebug(x) (void)0
#endif

const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    //quero guardar o proximo maior cara de cada elemento do meu array
    //quando o a[st.top] for maior que eu eu popo e guardo o indice
    stack<int> str;
    vector<int> nextmx(n);
    for (int i = n-1; i >= 0; i--){
        while (!str.empty() && a[str.top()] <= a[i]) str.pop();
        nextmx[i] = (str.empty() ? n : str.top());
        str.emplace(i);
    }
    debug(nextmx);
    
    stack<int> stl;
    vector<int> prevmx(n);
    for (int i = 0; i < n; i++){
        while (!stl.empty() && a[stl.top()] < a[i]) stl.pop();
        prevmx[i] = (stl.empty() ? -1 : stl.top());
        stl.emplace(i);
    }
    debug(prevmx);

    while (!str.empty()) str.pop();
    while (!stl.empty()) stl.pop();

    vector<int> nextmn(n);
    for (int i = n-1; i >= 0; i--){
        while (!str.empty() && a[str.top()] >= a[i]) str.pop();
        nextmn[i] = (str.empty() ? n : str.top());
        str.emplace(i);
    }
    debug(nextmn);

    vector<int> prevmn(n);
    for (int i = 0; i < n; i++){
        while (!stl.empty() && a[stl.top()] > a[i]) stl.pop();
        prevmn[i] = (stl.empty() ? -1 : stl.top());
        stl.emplace(i);
    }
    debug(prevmn);

    /*
    tenho os indices dos intervalos onde cada a[i] vai ser o valor minimo e maximo de um intervalo
    basta calcular o EV(Max) e EV(Min)
    */
    int evmx = 0, evmn = 0;
    for (int i = 0; i < n; i++){
        int lmx = (i - prevmx[i]);//ate onde ai e o maximo a esquerda
        int rmx = (nextmx[i] - i);//ate onde ai eh o maximo a direita
        int intervalsmx = (lmx * rmx) - 1; //numero de intervalos em quer a[i] eh o max 

        int lmn = (i - prevmn[i]);//ate onde ai e o minimo a esquerda
        int rmn = (nextmn[i] - i);//ate onde ai eh o minimo a direita
        int intervalsmn = (lmn * rmn) - 1; //numero de intervalos em quer a[i] eh o min 
        
        debug(intervalsmx, intervalsmn);

        evmx += a[i] * intervalsmx; 
        evmn += a[i] * intervalsmn; 
        debug(evmx, evmn);
        // cout << endl;
    }
    cout << evmx - evmn << endl;
}