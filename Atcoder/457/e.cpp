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
    vector<vector<pair<int,int>>> frente(n+1), tras(n+1);
    vector<int> min_r(n + 2, 2e18);
    map<pair<int,int>, int> mp;

    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        min_r[l] = min(min_r[l], r);
        int sz = r - l + 1;
        frente[l].emplace_back(sz,i);
        tras[r].emplace_back(sz,i);
        mp[{l,r}]++;
    }

    for (int i = n; i >= 1; i--) min_r[i] = min(min_r[i], min_r[i + 1]);

    for (int i = 0; i <= n; i++){
        sort(all(frente[i]));
        sort(all(tras[i]));
    } 

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if (mp[{l,r}] > 1){
            cout << "Yes" << endl;
            continue;
        }
        
        int tot = r - l + 1;
        int covered = 0;

        if (frente[l].size()){
            pair<int,int> target = {tot, 2e18};
            auto it = lower_bound(all(frente[l]), target);
            if (it != frente[l].begin()){
                it = prev(it);
                auto [szl, idl] = *it;
                covered += szl;
                debug(l, frente[l], covered, *it);
            }
        }

        if (covered == tot) {
            debug("precisou usar so um pra cobrir");
            if (min_r[l + 1] <= r || min_r[l] < r) cout << "Yes" << endl;
            else cout << "No" << endl;
            continue;
        }
        
        if (tras[r].size()){
            pair<int,int> target = {tot, 2e18};
            auto it = lower_bound(all(tras[r]), target);
            if (it != tras[r].begin()){
                it = prev(it);
                covered += it->first;
                debug(r, tras[r], covered, *it);
            }
        }
        
        if (covered >= tot) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

signed main(){
    winton;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}