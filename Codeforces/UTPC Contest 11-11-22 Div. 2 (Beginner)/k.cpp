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

const int P = 31; 
const int MOD = 972663749;
const int MAX = 1e4+7;

vector<vector<pair<int,int>>> graph;
int n;

struct hashing {
    int p_pow[MAX]; 
    vector<int> hashes[11];
    vector<string> strings;
    int n;
    
    hashing(int _n, vector<string> _a) : n(_n), strings(_a) {} 

    void build(){
        p_pow[0] = 1; 

        for (int i = 1; i < MAX; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < n; i++)hashes[i] = calcHash(strings[i]);
    }

    vector<string> trim(){
        vector<string> ret;
        //funcao pra remover do vetor original as strings que sao substrings de outras
        //nao preciso delas pra fazer a verificacao depois
        set<int> occurrences;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                int S = strings[i].size(), T = strings[j].size();
                int h_s = hashes[i][S];
                for (int k = 0; k + S - 1 < T; k++) {
                    int cur_h = (hashes[j][k+S] + MOD - hashes[j][k]) % MOD;
                    if (cur_h == h_s * p_pow[k] % MOD) occurrences.insert(i);
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (occurrences.find(i) != occurrences.end()) continue;
            ret.push_back(strings[i]);
        }
        debug(occurrences);
        return ret;
    }
    
    vector<int> calcHash(string s){
        vector<int> h(s.size() + 1, 0); 
        for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
        return h;
    }
    
    int get_hash(int l, int len, int idx){
        int r = l + len;
        return ((hashes[idx][r] + MOD - hashes[idx][l]) % MOD);
    }

    bool equal_substrings(int len, int i, int j) {
        if (!len) return true;

        int h1 = get_hash(0, len, i);
        int h2 = get_hash(strings[j].size() - len, len, j);
        // debug(h1, strings[i], len);
        // debug(h2, strings[j], len);
        
        int left  = (h1 * p_pow[strings[j].size()-len]) % MOD;
        int right = (h2) % MOD;
        // if (left == right){ debug(i, j, left, right, len);}
        return left == right;
    }
};

int dfs(int v, int cnt, int r, vector<int> visited){
    if (cnt == n) return r;
    visited[v] = 1;
    int cost = r;
    for (auto [u, c] : graph[v]){
        if (visited[u]) continue;
        cost = max(cost, dfs(u, cnt+1, r + c, visited));
        // debug(v, u, cost);
    }
    return cost;
}

signed main(){
    winton;
    cin >> n;
    vector<string> a(n);
    for (auto &s : a)cin >> s;
    
    hashing temp(n, a);
    temp.build();
    vector<string> novo = temp.trim();
    
    debug(novo);
    
    n = novo.size();
    hashing hash(n, novo);
    hash.build();
    
    graph.resize(n);
    int sum = 0;

    for (int i = 0; i < n; i++){
        sum += novo[i].size();
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            int cost = 0;
            int mx = min((int)novo[i].size(), (int)novo[j].size());
            for (int len = mx; len >= 1; len--) {
                if (hash.equal_substrings(len, i, j)) {
                    cost = len;
                    break;
                }
            }
            graph[j].push_back({i, cost});
        }
    }
    int ans = sum;
    for (int i = 0; i < n; i++){
        vector<int> visited(n, 0);
        debug(i,novo[i], graph[i]);
        int reduction = dfs(i, 1LL, 0LL, visited);
        ans = min(ans, sum - reduction);
        // debug(i, ans, reduction);
    }
    cout << ans << endl;
}

/*
find combinations of two string that have a prefix and suffix in common
woofer + two = twoofer
for each string i could find the longest prefix and suffix shared with another string 

but what if
woofer
two
woopiwo

best = twoopiwoofer
how do i stop woofer from taking woopiwo spot after two?
not good = twooferwoopiwo

i check for each string the longest suffix that is equal to a prefix of another string for all other strings
then i make a graph 
u connects to v with a cost (size of the longest common prefix/suffix) of c

1 woofer
2 two
3 woopiwo

1: {}
2: {1,2}, {3,2}
3: {1,2}

i guess if there is no connection then c = 0

maybe i make a dp 
i can brute test every start and every option and see which gives the best result
10! = 3e6

*/