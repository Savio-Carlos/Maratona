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
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif

signed main(){
    fastio;
    while (1) {
        int n; 
        cin >> n;
        if (n == 0) break;

        vector<int> a(n);
        for (auto &u : a) cin >> u;
        int mn = 1e9;
        vector<int> inv(n+1, 0);
        for (int i = n-1; i >= 0; i--){
            mn = min(mn,a[i]);
            if (a[i] > mn) inv[a[i]] = 1;
        }
        
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (inv[a[i]]) st.push(a[i]);
            else ans.push_back(a[i]);
            while (!st.empty() && ans.size() && st.top() == ans.back()+1){
                ans.push_back(st.top());
                st.pop();
            }
        }
        
        auto sorted = a;
        sort(all(sorted));
        
        if (ans == sorted) cout << "yes\n";
        else cout << "no\n";
    }
}
