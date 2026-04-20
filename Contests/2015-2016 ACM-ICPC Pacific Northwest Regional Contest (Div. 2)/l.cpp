#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

namespace dbg {
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
        cerr << s.substr(0, cpos) << " = " << h;
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
    #define debug(...) cerr << "[" << __func__ << ":" << __LINE__ << "]" << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

signed main(){
    int n, w;
    winton;
    cin >> n >> w;

    vector<int> v(n), safe(n);
    vector<ld> p(n);

    auto happy = [&](ld x){
        return log((ld)(1 + x/(ld)w));
    };

    int last = -1;
    ld e = 0;
    ld best = 0;
    ld cur_prob = 1.0;
    for (int i = 0; i < n; i++){
        //at each step i can give up and win last correct 
        //or i can continue and for the next question
        //i have a 1-pi chance of getting it wrong and winning last safe value
        //i have a pi chance of going to next question garanteeing the money
        string s;
        cin >> s;
        cin >> p[i] >> v[i];
        
        
        if (last != -1) e += (cur_prob * (1.0 - p[i])) * happy(v[last]);
        best = max(best, e + (cur_prob * p[i] * happy(v[i])));
        
        cur_prob *= p[i];

        if (s == "safe"){
            last = i;
            safe[i] = 1;
        } 
    }   
    debug(e, best);

    ld l = 0, r = 1e18;
    ld ans;
    for (int i = 0; i < 200; i++){
        ld mid = (l + r) / 2.0;
        if (happy(mid) < best) l = mid;
        else r = mid;
        ans = mid;
    }
    cout << "$" << fixed << setprecision(2) << ans << endl;
}
