#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n;
    cin >> n;
    map<int, set<int>> mp;
    vector<int> ones;

    map<pair<int,int>, bool> all;

    int first = 1e9+7;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        first = min(first, x);
        all[{x,y}] = true;
        if (y == 1) ones.push_back(x);
        else mp[x].insert(y);
    }
    int tot = mp.size();
    int cnt = 0;

    int last = 1;
    vector<pair<int,int>> ans;
    for (auto [xi, st] : mp){
        if (all.find({xi, 2}) == all.end()) ans.emplace_back(xi, 2);
        for (auto yi : st) ans.emplace_back(xi, yi);
        last = xi+1;
        ans.emplace_back(last, 2);
        all[{last,2}] = true;
    }
    // ans.emplace_back(last, 1);
    if(mp.empty()) ans.emplace_back(first, 2);
    sort(rall(ones));
    for (auto u : ones) {
        if (u == last) continue;
        ans.emplace_back(u, 1);
        all[{u,1}] = true;
    }
    if (all.find({first,1}) == all.end()) ans.emplace_back(first,1);
    cout << ans.size() << endl;
    for (auto [x,y] : ans) cout << x << " " << y << endl;
}