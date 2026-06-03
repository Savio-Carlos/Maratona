#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<typename... T> istream& operator>>(istream& is, tuple<T...>& t) { apply([&is](auto&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<typename T, size_t N> istream& operator>>(istream& is, T (&arr)[N]) { for (auto& x : arr) is >> x; return is; }
template<size_t N> istream& operator>>(istream& is, array<int, N>& arr) { for (auto& x : arr) is >> x; return is; }

namespace dbg {
    constexpr const char* RESET      = "\033[0m";
    constexpr const char* BOLD_BLUE  = "\033[1;34m";
    constexpr const char* YELLOW     = "\033[33m";
    constexpr const char* BOLD_WHITE = "\033[1;37m";

    template<typename T, typename = void> struct is_container : false_type {};
    template<typename T> struct is_container<T, void_t<typename T::value_type>> : bool_constant<!is_same_v<T, string> && !is_same_v<T, string_view>> {};

    inline ostream& print_atom(ostream& os, bool b)         { return os << (b ? "true" : "false"); }
    inline ostream& print_atom(ostream& os, char c)         { return os << '\'' << c << '\''; }
    inline ostream& print_atom(ostream& os, const string& s){ return os << '"' << s << '"'; }
    inline ostream& print_atom(ostream& os, string_view s)  { return os << '"' << s << '"'; }
    inline ostream& print_atom(ostream& os, const char* s)  { return os << '"' << s << '"'; }

    template<typename T, enable_if_t<!is_container<T>::value, int> = 0>
    ostream& print_atom(ostream& os, const T& x) { return os << x; }

    template<typename T1, typename T2>
    ostream& print_atom(ostream& os, const pair<T1, T2>& p) {
        os << '{'; print_atom(os, p.first); os << ", "; print_atom(os, p.second); return os << '}';
    }
    template<typename... T>
    ostream& print_atom(ostream& os, const tuple<T...>& t) {
        os << '{';
        apply([&os](auto const&... args) {
            size_t n = 0;
            ((print_atom(os, args), os << (++n != sizeof...(T) ? ", " : "")), ...);
        }, t);
        return os << '}';
    }

    template<typename T, typename C>
    ostream& print_atom(ostream& os, stack<T, C> s) {
        os << '{'; bool f = true; while (!s.empty()) { if (!f) os << ", "; print_atom(os, s.top()); s.pop(); f = false; } return os << '}';
    }
    template<typename T, typename C>
    ostream& print_atom(ostream& os, queue<T, C> q) {
        os << '{'; bool f = true; while (!q.empty()) { if (!f) os << ", "; print_atom(os, q.front()); q.pop(); f = false; } return os << '}';
    }
    template<typename T, typename C, typename Cmp>
    ostream& print_atom(ostream& os, priority_queue<T, C, Cmp> q) {
        os << '{'; bool f = true; while (!q.empty()) { if (!f) os << ", "; print_atom(os, q.top()); q.pop(); f = false; } return os << '}';
    }

    template<typename C, enable_if_t<is_container<C>::value, int> = 0>
    ostream& print_atom(ostream& os, const C& v) {
        os << '{'; bool f = true;
        for (const auto& x : v) { if (!f) os << ", "; print_atom(os, x); f = false; }
        return os << '}';
    }

    template<typename C, enable_if_t<is_container<C>::value, int> = 0>
    ostream& operator<<(ostream& os, const C& v)            { return print_atom(os, v); }
    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return print_atom(os, p); }
    template<typename... T>
    ostream& operator<<(ostream& os, const tuple<T...>& t)  { return print_atom(os, t); }

    inline size_t split_arg(string_view s) {
        int depth = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '"' || c == '\'') {
                char q = c; ++i;
                while (i < s.size() && s[i] != q) { if (s[i] == '\\' && i + 1 < s.size()) ++i; ++i; }
            } else if (c == '(' || c == '[' || c == '{' || c == '<') ++depth;
            else if (c == ')' || c == ']' || c == '}' || c == '>') --depth;
            else if (c == ',' && depth == 0) return i;
        }
        return string_view::npos;
    }

    inline void debug_out(string_view) { cerr << '\n' << flush; }
    template<typename H, typename... T>
    void debug_out(string_view s, const H& h, const T&... t) {
        size_t cpos = split_arg(s);
        auto name = s.substr(0, cpos);
        while (!name.empty() && (name.front() == ' ' || name.front() == '\t')) name.remove_prefix(1);
        while (!name.empty() && (name.back()  == ' ' || name.back()  == '\t')) name.remove_suffix(1);
        cerr << YELLOW << name << RESET << " = " << BOLD_WHITE;
        print_atom(cerr, h) << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            debug_out(cpos == string_view::npos ? string_view{} : s.substr(cpos + 1), t...);
        } 
        else cerr << '\n' << flush;
    }
}
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) do { cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "] " << RESET; dbg::debug_out(#__VA_ARGS__, __VA_ARGS__); } while (0)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) ((void)0)
#endif

const int INF = 1e18;
const int MAX = 2e5+7;

vector<bool> is_prime(MAX + 1, true);

void sieve() {
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= MAX; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= MAX; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
}

struct Dinic {
    struct edge { 
        int to, cap, rev, flow;
        bool res; 
        edge(int to_, int cap_, int rev_, bool res_) : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };
    vector<vector<edge>> graph;
    vector<int> level, beg;
    int n;
    int fluxo;
 
    Dinic(int n) : n(n), graph(n), level(n), beg(n), fluxo(0) {}
 
    void add(int a, int b, int c) {
        graph[a].emplace_back(b, c, (int)graph[b].size(), false);
        graph[b].emplace_back(a, 0, (int)graph[a].size() - 1, true);
    }
 
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        fill(beg.begin(), beg.end(), 0);
        level[s] = 0; 
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (auto &e : graph[u]){
                if (level[e.to] != -1 or (e.flow == e.cap)) continue;
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
                
        }
        return level[t] >= 0;
    }
 
    int dfs(int v, int t, int f = INF) {
        if (v == t or !f) return f;
 
        for (int &i = beg[v]; i < (int)graph[v].size(); i++) {
            auto &e = graph[v][i];
            if (level[e.to] != level[v] + 1) continue;
 
            int d = dfs(e.to, t, min(f, e.cap - e.flow));
            
            if (!d) continue; 
            e.flow += d;
            graph[e.to][e.rev].flow -= d;
            return d;
            }
        return 0;
    }
 
    int max_flow(int s, int t) {
        while (bfs(s, t)) {
            while (int f = dfs(s, t)) fluxo += f;
        }
        return fluxo;
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vector<tuple<int,int,int>> a(n);
    for (auto &[p, c, l] : a) cin >> p >> c >> l;
    
    auto check = [&](int mid) -> bool{
        int S = 0, T = n + 2;
        Dinic dinic(n+3);
        int node = 1, sum = 0;
        vector<int> odd, even;
        vector<int> magic;
        
        int best1 = 0;

        for (auto [p, c, l] : a){
            if (l > mid) continue;
            // debug(mid, p, c, l);
            if (c == 1){
                best1 = max(best1, p);
                continue;
            }
            if (c&1){
                dinic.add(node, T, p);
                odd.push_back(node);
            }
            else{
                dinic.add(S, node, p);
                even.push_back(node);
            } 
            magic.push_back(c);
            node++;
            sum += p;
        }

        if (best1){
            sum += best1;
            odd.push_back(node);
            magic.push_back(1);
            dinic.add(node, T, best1);
        }
        debug(odd, magic, even);
        for (int e = 0; e < even.size(); e++){
            for (int o = 0; o < odd.size(); o++){
                if (is_prime[magic[even[e] - 1] + magic[odd[o] - 1]]){
                    dinic.add(even[e], odd[o], INF);
                }
            }
        }


        int fl = dinic.max_flow(S, T);
        debug(mid, fl, sum-fl);
        return (sum-fl >= k);
    };

    int l = 1, r = n;
    int ans = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}

signed main(){
    winton;
    sieve();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
