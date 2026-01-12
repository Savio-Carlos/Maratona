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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    int m = n - 1;
    vector<int> diff(m);
    for (int i = 0; i < m; i++) {
        diff[i] = abs(a[i] - a[i+1]);
    }
    debug(diff);

    vector<int> left(m), right(m);
    //achar o primeiro menor valor para esquerda e direita de cada elemento do diff
    stack<int> s;
    for (int i = 0; i < m; i++) {
        while (!s.empty() && diff[s.top()] >= diff[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = m - 1; i >= 0; i--) {
        while (!s.empty() && diff[s.top()] > diff[i]) {
            s.pop();
        }
        right[i] = s.empty() ? m : s.top();
        s.push(i);
    }
    debug(left, right);

    vector<int> ans(n + 2, 0); 
    //ans[i] = quantos subarrays sao exquisite

    for (int i = 0; i < m; i++) {
        //comeco do subarray vai ser qualquer indice a partir de l[i] + 1 ate i, total = i - l[i]
        //fim do subarray vai ser qualquer indice a partir de i ate r[i] - 1, total = r[i] - i
        int cnt = (i - left[i]) * (right[i] - i);
        //numero de subarrays que diff i e o min e quantos na esquerda * direita
        ans[1] += cnt;
        debug(cnt, left[i], right[i]);
        if (diff[i] + 1 <= n) {
            ans[diff[i] + 1] -= cnt;
            //se ele e exquisite pra diff[i] q e o min no intervalo, ele tambem e exquisite para todo k de 1 ate diff[i], mas n depois desse valor
        }
        // debug(ans); 
    }
    debug(ans);
    for (int i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}