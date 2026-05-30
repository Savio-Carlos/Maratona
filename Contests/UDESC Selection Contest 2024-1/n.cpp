
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    template<class A, class B> ostream& operator<<(ostream& o, const pair<A,B>& p) {
        return o << '(' << p.first << ", " << p.second << ')';
    }
    template<class T, class = enable_if_t<!is_same_v<T,string> && !is_same_v<T,string_view>>>
    auto operator<<(ostream& o, const T& v) -> decltype(v.begin(), o) {
        o << '{'; bool f = 1;
        for (auto& x : v) { o << (f ? "" : ", ") << x; f = 0; }
        return o << '}';
    }
    void out(string_view) { cerr << '\n'; }
    template<class H, class... T> void out(string_view s, H h, T... t) {
        auto c = s.find(',');
        cerr << s.substr(0, c) << " = " << h;
        if constexpr (sizeof...(t)) {
            cerr << " | ";
            out(s.substr(s.find_first_not_of(" ,", c)), t...);
        } 
        else cerr << '\n';
    }
}
using namespace dbg;

// #define DEBUG

#ifdef DEBUG
    #define winton (void)0
    #define debug(...) cerr << "[" << __LINE__ << "] ", out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

signed main(){
    winton;
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> row(n+1, 0);
    vector<int> col(m+1, 0);

    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int x, y;
            cin >> x >> y;
            row[x] = 1;
            col[y] = 1;
        }
        else {
            int xi, yi, xf, yf;
            cin >> xi >> yi >> xf >> yf;

            debug((row[xf] || col[yf]));
            if ((row[xi] || col[yi]) && (row[xf] || col[yf])) cout << "SIM" << endl;
            else cout << "NAO" << endl;
        }
    }
}