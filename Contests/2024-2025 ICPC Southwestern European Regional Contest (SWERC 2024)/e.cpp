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
    set<pair<int,int>> req;
    int mx = 1;
    int first = 1e9+7;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        first = min(first, x);
        mx = max(mx, x);
        req.insert({x,y});
        if (y == 1) ones.push_back(x);
        else mp[x].insert(y);
    }
    int tot = mp.size();
    int cnt = 0;

    int last = 1;
    vector<pair<int,int>> ans;

    auto add = [&](int x, int y){
        if (x < 1 || x > 1e9) return;
        if (all.find({x,y}) != all.end()) return;
        if(!ans.empty() && ans.back() == make_pair(x, y)) return;
        ans.emplace_back(x, y);
        all[{x,y}] = true;
    };

    for (auto [xi, st] : mp){
        if (xi == mx && xi != 1){
            vector<int> temp;
            for (auto yi : st) temp.emplace_back(yi);
            sort(rall(temp));
            if (xi > 1) add(xi-1, 2);
            else if (xi < 1e9) add(xi + 1, 2);

            for (auto yi : temp) add(xi, yi);
            if (!ans.empty() && ans.back().second > 1) { 
                add(xi, 1);
            }
            last = xi;
            break;
        }
        add(xi, 2);
        for (auto yi : st) add(xi, yi);
        if (xi+1 == mx) continue;
        last = xi+1;
        add(last, 2);
    }
    if (mp.empty()){
        sort(all(ones));
        for (auto u : ones) add(u, 1);
        add(mx, 2);
        add(first, 2);
        add(first, 1);
    } else {
        add(mx, 1);
        if(mp.empty()) add(first, 2);
        sort(rall(ones));
        for (auto u : ones) add(u, 1);
        add(first,1);
    }

    vector<pair<int,int>> comp;
    for (auto &p : ans) {
        if (comp.size() < 2) {
            comp.push_back(p);
            continue;
        }
        auto A = comp[comp.size()-2];
        auto B = comp[comp.size()-1];
        auto C = p;
        int x1 = B.first - A.first;
        int y1 = B.second - A.second;
        int x2 = C.first - B.first;
        int y2 = C.second - B.second;
        if (x1 * y2 - y1 * x2 == 0) {
            if (req.find(B) == req.end()) {
                comp.pop_back();
                comp.push_back(C);
            } 
            else comp.push_back(C);
        } 
        else comp.push_back(C);
    }

    while (comp.size() >= 3) {
        auto A = comp[comp.size()-2];
        auto B = comp[comp.size()-1];
        auto C = comp[0];
        int x1 = B.first - A.first;
        int y1 = B.second - A.second;
        int x2 = C.first - B.first;
        int y2 = C.second - B.second;
        if (x1 * y2 - y1 * x2 == 0) {
            if (req.find(B) == req.end()) {
                comp.pop_back();
            } else break;
        } else break;
    }

    while (comp.size() >= 3) {
        auto A = comp.back();
        auto B = comp[0];
        auto C = comp[1];
        int x1 = B.first - A.first;
        int y1 = B.second - A.second;
        int x2 = C.first - B.first;
        int y2 = C.second - B.second;
        if (x1 * y2 - y1 * x2 == 0) {
            if (req.find(B) == req.end()) {
                comp.erase(comp.begin());
            } else break;
        } else break;
    }

    cout << comp.size() << endl;
    for (auto [x,y] : comp) cout << x << " " << y << endl;
}
