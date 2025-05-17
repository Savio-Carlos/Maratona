#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto &u : p) cin >> u;
        stack<pair<int,int>> st;

        for (int i = 0; i < n; i++){
            pair<int,int> cur = {p[i],p[i]};
            while(!st.empty() && cur.second < st.top().first){
                st.top().first = max(cur.first,  st.top().first);
                st.top().second = min(cur.second,  st.top().second);
                cur = st.top();
                st.pop();
            }
            //cout << cur.first << " -  " << cur.second << endl;
            st.push(cur);

        }

        cout << st.size() << endl;
    }
}