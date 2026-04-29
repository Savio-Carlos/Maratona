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

const int MOD = 676767677;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    sort(all(a));

    auto check = [&](int mid) {
        vector<int> visited(mid, 0);//quero achar todos os valores ate mid-1, para o mex ser mid1
        vector<int> extras, missing;
        
        for (auto u : a) {
            if (u < mid && !visited[u]) visited[u] = 1;
            else extras.push_back(u);
        }
        
        for (int i = 0; i < mid; i++) {
            if (!visited[i]) missing.push_back(i);
        }
        
        if (missing.size() > extras.size()) return false;
        
        int diff = extras.size() - missing.size();
        for (int i = 0; i < missing.size(); i++) {
            if (extras[diff + i] < 2 * missing[i] + 1) return false;
        }
        return true;
    };

    int ans = 0;
    int l = 0, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } 
        else r = mid - 1;
    }

    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}


/*
calcular mex inicial pra ver se ja e o melhor

quando eu perco um valor no mex?
no caso do              2 3 3 4 4 5 8 9 9
eu quero transformar em 2 3 0 4 1 5 6 -> not possible
	      faco bi = 9 9 3 9 5 9
pra fazer um mex preciso ter 
1. o mex ja presente no array, dai escolho um numero > que ele para bi
2. o mex não esta presente, preciso de algum numero no array que seja maior que 2*ai, e dai escolhemos ai+1 como bi

vejo os caras que ja tenho, vejo quantos repetidos tenho
para os mex que não tenho, começando do 0, vou pegando dos repetidos
se eu n tiver mais repetidos, vou pegando dos maiores números que ja tenho no array
sempre seguindo as duas regras acima para achar o cur mex
da pra fazer bs no mex e ver se consigo fazer aquele mex
vejo quantos numeros eu tenho ate o mid e quantos faltam, depois vejo se consigo fazer todos que faltam

*/