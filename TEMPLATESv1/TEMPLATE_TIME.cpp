#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

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

#define DEBUG

#if defined(DEBUG)
    #define bg3 (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__) ;
#else
    #define bg3 ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

signed main(){
    bg3;
}