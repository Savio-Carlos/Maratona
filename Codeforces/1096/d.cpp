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

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

struct SegTree {
    vector<int> tree;
    int n;
    SegTree(int n) : n(n) {
        tree.assign(4 * n + 4, -1);
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int idx, int val) {
        update(1, 0, n, idx, val);
    }
    int query(int node, int l, int r, int limit) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (tree[2 * node] < limit) return query(2 * node, l, mid, limit);
        return query(2 * node + 1, mid + 1, r, limit);
    }
    int query(int limit) {
        return query(1, 0, n, limit);
    }
};

vector<int> manacher_odd(vector<int> s) {
    int n = s.size();
    s.insert(s.begin(), -1);
    s.push_back(-2);
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0LL, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return vector<int>(p.begin() + 1, p.end() - 1);
}

vector<int> manacher(const vector<int> &s) {
    vector<int> t;
    for (auto c : s) {
        t.push_back(-3);
        t.push_back(c);
    }
    t.push_back(-3);
    auto res = manacher_odd(t);
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for (auto &u : a) cin >> u;

    vector<int> mnc = manacher(a);
    vector<pair<int, int>> palindromes;
    for (int i = 0; i < mnc.size(); i++) {
        if (mnc[i] - 1 > 0) {
            palindromes.push_back({mnc[i] - 1, i});
        }
    }

    vector<vector<pair<int, int>>> queries(2*n);
    for (auto& p : palindromes) {
        int size = p.first;
        int centro = p.second;
        int st = (centro - size) / 2;
        int en = st + size - 1;
        queries[en].push_back({st, size});
    }

    SegTree st(n+1);
    int ans = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (a[i] <= n) st.update(a[i], i);
        for (auto& [l, _] : queries[i]) {
            int mex = st.query(l);
            ans = max(ans, mex);
        }
    }
    cout << ans << endl;
}

signed main() {
    winton;
    int t;
    cin >> t;
    while (t--) solve();
}

