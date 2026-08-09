#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()

signed main(){
    winton;
    string s;
    cin >> s;
    stack<int> st;
    for (auto u : s){
        if (u == '#'){
            if (!st.empty()) st.pop();
        }
        else st.push(u);
    }
    vector<char> ans;
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(all(ans)); 
    // for (auto u : ans)cout << u << ' ';
    // cout << endl;
    
    int k; 
    cin >> k;
    k--;
    if (k >= ans.size()) cout << -1 << endl;
    else cout << ans[k] << endl; 
}
