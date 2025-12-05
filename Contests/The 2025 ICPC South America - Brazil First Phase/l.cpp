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
query = i love star

star star wars star peace
candidatas: {star, wars, peace}
métrica de similaridade e o produto interno dos vetores 
para cada palavra D do texto, fazer o produto vetorial entre o vetor dela e o vetor da palavra candidata
S(d) e o somatório de todos esses produtos
no final escolhe-se a palavra com maior S(d)

*/

const int MAX = 1e3+7;
const int INF = 1e18;

int dot(const pair<int,int>& v, const pair<int,int>& w){
    return (v.first * w.first + v.second * w.second);
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<string> dicionario(n);
    vector<pair<int,int>> vetores(n);
    map<string,int> mp;
    for (int i = 0; i < n; i++){
        cin >> dicionario[i];
        cin >> vetores[i].first >> vetores[i].second;
        mp[dicionario[i]] = i;
    }
    int m;
    cin >> m;
    vector<string> base(m);
    for(auto &u : base) cin >> u;
    int q, k;
    cin >> q >> k;
    while(q--){
       int f;
        cin >> f;
        vector<string> query(f);
        for(auto &x : query) cin >> x;

        bool found = false;
        string ans = "*";

        for(int ii = k; ii >= 1; ii--){
            pair<int, int> sum = {0, 0};
            bool exist = false;

            for(int i = 0; i < m - ii; i++){
                bool match = true;
                for(int j = 0; j < ii; j++){
                    if(base[i+j] != query[f - ii + j]){
                        match = false;
                        break;
                    }
                }

                if(match){
                    exist = true;
                    string prox = base[i + ii];
                    if(mp.find(prox) != mp.end()){
                        int idx = mp[prox];
                        sum.first += vetores[idx].first;
                        sum.second += vetores[idx].second;
                    }
                }
            }

            if(exist){
                int mx = -INF;
                int best = -1;

                for(int i = 0; i < n; i++){
                    int score = dot(vetores[i], sum);
                    if(score > mx){
                        mx = score;
                        best = i;
                    }
                }
                
                ans = dicionario[best];
                found = true; 
                break;
            }
        }
        for(auto x : query) cout << x << " ";
        cout << ans << endl;
    }
}