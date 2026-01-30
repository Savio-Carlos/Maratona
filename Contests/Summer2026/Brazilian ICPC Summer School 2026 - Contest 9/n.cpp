#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cout << x << " "; 
#define endl '\n'

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<tuple<int,int,int>> zorcs(n);
    int i = 1;
    for(auto &[a, b, idx] : zorcs){
        cin >>  a >> b;
        idx = i++;
    }
    int m;
    cin >> m;
    i = 1;
    vector<tuple<int,int,int>> axes(m);
    for(auto &[w, c, idx] : axes){
        cin >>  w >> c;
        idx = i++;
    }
    
    sort(zorcs.rbegin(), zorcs.rend());
    sort(axes.rbegin(), axes.rend());
    
    vector<int> ans(n + 1);
    multiset<pair<int, int>> s;
    
    int m_idx = 0;
    for (int i = 0; i < n; i++) {
        auto [a, b, z_idx] = zorcs[i];
        while (m_idx < m) {
            auto [w, c, ax_idx] = axes[m_idx];
            if (w < a) break;
            s.insert({c, ax_idx});
            m_idx++;
        }
        auto it = s.lower_bound({b, -1});
        if (it == s.end()) {
            cout << -1 << endl;
            return 0;
        }
        ans[z_idx] = it->second;
        s.erase(it);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
