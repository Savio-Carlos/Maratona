#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

const int INF = 1e18;

signed main(){
    winton;
    int n, q;
    cin >> n >> q;
    set<int> st;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.insert(x);
    }

    st.insert(INF);
    st.insert(INF+1);
    st.insert(-INF);
    st.insert(-INF+1);

    while(q--){
        int x;
        cin >> x;
        st.insert(x);

        int ans = 1e9;
        
        {
            auto it = st.upper_bound(x);
            it++;
            int a = x;
            int c = *it;
            ans = min(ans, c-a);
            // debug(ans);
        }
        {
            auto it = st.lower_bound(x);
            it--;
            int a = *it;
            it = st.upper_bound(x);
            int c = *it;
            ans = min(ans, c-a);
            // debug(ans);
        }
        {
            auto it = st.lower_bound(x);
            it--;
            it--;
            int a = *it;
            int c = x;
            ans = min(ans, c-a);
            // debug(a);
            // debug(ans);
        }
        st.erase(st.find(x));
        cout << ans << endl;
    }
}
