#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n), pfx(n+1);
    for (auto &u : a) cin >> u;
    pfx[0] = 0;
    for (int i = 1; i <= n; i++) pfx[i] = a[i-1] + pfx[i-1];
   
    
    //topo da pilha sempre tem que ter o maior cara depois de mim
    //entao sempre que o arr[top] > a[i] eu removo
    vector<int> next(n);
    stack<int> st;
    for (int i = n-1; i >= 0; i--){
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        next[i] = st.empty() ? -1 : st.top();
        st.emplace(i);
    }
    // vdebug(next);

    vector<int> r = a;
    reverse(all(r));
    // vdebug(r);

    vector<int> prev(n);
    stack<int> st2;
    for (int i = n-1; i >= 0; i--){
        while (!st2.empty() && r[st2.top()] < r[i]) st2.pop();
        prev[n-i-1] = st2.empty() ? -1 : n-st2.top()-1;
        st2.emplace(i);
    }
    // vdebug(prev);
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (next[i] != -1 && next[i] != i){
            int size = next[i] - i - 1;
            int mn = min(a[next[i]], a[i]);
            int area = (mn * size) - (pfx[next[i]] - pfx[i+1]);
            ans = max(ans, area);
            // debug(area);
        }
        if (prev[i] != -1 && prev[i] != i){
            int size = i - prev[i] - 1;
            int mn = min(a[prev[i]], a[i]);
            int area = (mn * size) - (pfx[i] - pfx[prev[i]+1]);
            ans = max(ans, area);
            // debug(pfx[i]);
            // debug(pfx[prev[i]+2]);
            // debug(size);
            // debug(mn);
            // debug(area);
        }
    }

    cout << ans << endl;
}