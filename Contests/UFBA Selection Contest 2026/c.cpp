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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) do { cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "] " << RESET; dbg::debug_out(#__VA_ARGS__, __VA_ARGS__); } while (0)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) ((void)0)
#endif

vector<int> manacher(const vector<int>& s) {
    int n = s.size();
    vector<int> t(2 * n + 1, -1);
    for (int i = 0; i < n; i++) t[2 * i + 1] = s[i];

    int m = t.size();
    vector<int> u(m + 2);
    u[0] = -2;
    u[m + 1] = -3;
    for (int i = 0; i < m; i++) u[i + 1] = t[i];
 
    vector<int> p(m + 2, 0);
    int l = 0, r = 1;
    for (int i = 1; i <= m; i++) {
        if (i < r) p[i] = min((r - i), p[l + (r - i)]);
        while (u[i - p[i]] == u[i + p[i]]) p[i]++;
        if (i + p[i] > r) { 
            l = i - p[i]; 
            r = i + p[i]; 
        }
    }
    return vector<int>(p.begin() + 1, p.begin() + m + 1);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    cin >> grid;
 
    int l = 2 * m;
    vector<vector<vector<int>>> w(n, vector<vector<int>>(n, vector<int>(l - 1)));
 
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            vector<int> d;
            for (int k = 0; k < m; k++) {
                d.push_back(grid[a][k]);
                d.push_back(grid[b][k]);
            }
            vector<int> p = manacher(d);
           
            for (int c = 0; c <= l - 2; c++) {
                int half_t = p[2*c+2];
                int half_d = half_t / 2;
 
                int max_w = min({half_d, (c + 1), (l - 1 - c)});
                if (((c + max_w) & 1) == 0) max_w--;
                max_w = max(0LL, max_w);
                w[a][b][c] = max_w;
            }
        }
    }
 
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        vector<int> cur_w(l - 1);
        for (int c = 0; c <= l - 2; c++) cur_w[c] = w[i][i][c];
        for (int c = 0; c <= l - 2; c++) ans = max(ans, cur_w[c]);
        
        for (int k = 1; i - k >= 0 && i + k < n; k++) {
            int a = i - k, b = i + k;
            int height = 2 * k + 1;
            for (int c = 0; c <= l - 2; c++) {
                cur_w[c] = min(cur_w[c], w[a][b][c]);
                ans = max(ans, height * cur_w[c]);
            }
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        vector<int> cur_w(l - 1);
        for (int c = 0; c <= l - 2; c++) cur_w[c] = w[i][i+1][c];
        for (int c = 0; c <= l - 2; c++) ans = max(ans, 2 * cur_w[c]);
        
        for (int k = 2; i - k + 1 >= 0 && i + k < n; k++) {
            int a = i - k + 1, b = i + k;
            int height = 2 * k;
            for (int c = 0; c <= l - 2; c++) {
                cur_w[c] = min(cur_w[c], w[a][b][c]);
                ans = max(ans, height * cur_w[c]);
            }
        }
    }
 
    cout << ans << endl;
}
signed main(){
    winton;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}

