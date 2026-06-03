#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

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

void solve(){

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    vector<vector<int>> id(n, vector<int>(m, -1));
    vector<pair<int,int>> cells;
    cells.reserve(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                id[i][j] = (int)cells.size();
                cells.push_back({i, j});
            }
        }
    }
    int K = (int)cells.size();
    if (K == 1) {
        cout << "! " << cells[0].first + 1 << " " << cells[0].second + 1 << '\n' << flush;
        return;
    }

    const int DIRS = 4;
    const int dr[DIRS] = {-1, 0, 1, 0};
    const int dc[DIRS] = {0, 1, 0, -1};
    const char dch[DIRS] = {'U', 'R', 'D', 'L'};

    vector<array<int, DIRS>> nxt(K);
    vector<array<int, DIRS>> can(K);
    for (int v = 0; v < K; v++) {
        auto [r, c] = cells[v];
        for (int d = 0; d < DIRS; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && id[nr][nc] != -1) {
                nxt[v][d] = id[nr][nc];
                can[v][d] = 1;
            } else {
                nxt[v][d] = v;
                can[v][d] = 0;
            }
        }
    }

    const int maxQ = (int)(2LL * (n * m + n + m));
    int usedQ = 0;

    vector<int> seen(K, 0);
    int token = 1;
    auto step = [&](const vector<int>& S, int d, int expected) {
        token++;
        vector<int> res;
        res.reserve(S.size());
        for (int v : S) {
            if (can[v][d] != expected) continue;
            int to = nxt[v][d];
            if (seen[to] == token) continue;
            seen[to] = token;
            res.push_back(to);
        }
        return res;
    };

    function<int(const vector<int>&, int)> eval = [&](const vector<int>& S, int depth) -> int {
        if ((int)S.size() <= 1) return (int)S.size();
        if (depth == 0) return (int)S.size();
        int best = (int)S.size();
        for (int d = 0; d < DIRS; d++) {
            auto S0 = step(S, d, 0);
            auto S1 = step(S, d, 1);
            int worst = 0;
            if (!S0.empty()) worst = max(worst, eval(S0, depth - 1));
            if (!S1.empty()) worst = max(worst, eval(S1, depth - 1));
            best = min(best, worst);
        }
        return best;
    };

    auto ask = [&](int d) {
        cout << "? " << dch[d] << '\n' << flush;
        int r;
        if (!(cin >> r)) exit(0);
        if (r == -1) exit(0);
        return r;
    };

    vector<int> cand(K);
    iota(cand.begin(), cand.end(), 0);

    while ((int)cand.size() > 1) {
        if (usedQ >= maxQ) break;

        int depth = 3;
        if ((int)cand.size() <= 32) depth = 4;
        if ((int)cand.size() <= 8) depth = 5;

        int bestD = 0;
        int bestWorst = (int)cand.size();
        int bestSum = (int)cand.size() * 2;

        for (int d = 0; d < DIRS; d++) {
            auto S0 = step(cand, d, 0);
            auto S1 = step(cand, d, 1);
            int worst = 0;
            if (!S0.empty()) worst = max(worst, eval(S0, depth - 1));
            if (!S1.empty()) worst = max(worst, eval(S1, depth - 1));
            int sum = (int)S0.size() + (int)S1.size();
            if (make_tuple(worst, sum, d) < make_tuple(bestWorst, bestSum, bestD)) {
                bestWorst = worst;
                bestSum = sum;
                bestD = d;
            }
        }

        int resp = ask(bestD);
        usedQ++;
        auto nextCand = step(cand, bestD, resp);
        if (nextCand.empty()) exit(0);
        cand.swap(nextCand);
    }

    int v = cand[0];
    cout << "! " << cells[v].first + 1 << " " << cells[v].second + 1 << '\n' << flush;
}

signed main(){
    winton;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}