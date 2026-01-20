#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() {cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define winton ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif

void solve(){
    string s;
    cin >> s;
    int cnt = 0;
    int n = s.size();
    int ans = 0;
    stack<pair<int,int>> st;
    for (int i = 0; i < n; i++){
        if (s[i] == '('){
            st.push({i, 0});
            cnt++;
        }
        else {
            auto [pos, h] = st.top();
            if (h > 0){
                int mx = h;
                while (st.top().second != 0){
                    mx = max(st.top().second, mx);
                    st.pop();
                }
                st.top().second = mx + 1;
            }
            else {
                st.top().second = 1;
            }
            auto &[beg, he] = st.top();

            if (cnt&1) ans += (i - beg) * he;
            else ans -= (i - beg) * he;
            debug(i, beg, he, ans);
            cnt--;
        }
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while (t--) solve();
}