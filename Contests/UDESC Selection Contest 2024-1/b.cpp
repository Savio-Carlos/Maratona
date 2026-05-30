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

/*
%3 is losing position
xor the piles %3
each pile can be 1 2 or 0 under %3
if we double a pile 1, it becomes 2, same reversed
if the xor sum final %3 == 0 then giovana wins
so she wants to make the xor sum %3
this happens when there is when both 1 and 2 are even
x parity changes available
if there are no piles %3=0 then she is forced to do x change operations

*/

signed main(){
    winton;
    int n, x;
    cin >> n >> x;
    int ans = 0;
    int c1 = 0, c2 = 0, c0 = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a%3 == 1) c1++;
        if (a%3 == 2) c2++;
        if (a%3 == 0) c0++;
        ans ^= (a%3);
    }

    if (c1%2 == 0 && c2%2 == 0){
        if (c0) cout << "GIOVANA" << endl;
        else if (x%2 == 0) cout << "GIOVANA" << endl;
        else cout << "JULIA" << endl;
    }
    else if (c1%2 != c2%2) cout << "JULIA" << endl;
    else {
        if (c0){
            cout << "GIOVANA" << endl;
        } 
        else if (x%2 == 1) cout << "GIOVANA" << endl;
        else cout << "JULIA" << endl;
    }
}