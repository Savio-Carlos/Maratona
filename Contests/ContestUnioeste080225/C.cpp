#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<pair<int,int>> points(n);
        unordered_set<int> y0, y1;

        for (auto &[x,y]: points){
            cin >> x >> y;
            if (y == 0) y0.insert(x);
            else y1.insert(x);
        }
        
        sort (points.begin(), points.end());
        int ans = 0;
        int xis = 0;
        for (int i = 1; i < n; i++){
            if (points[i].first == points[i-1].first) xis++;     
        }
        ans += xis * (n-2);

        for (int x : y1) {
            int x1 = x-1;
            int x2 = x+1;
            if(y0.find(x1) != y0.end() && y0.find(x2) != y0.end()) ans++;
        }
        for (int x : y0) {
            int x1 = x-1;
            int x2 = x+1;
            if(y1.find(x1) != y1.end() && y1.find(x2) != y1.end()) ans++;
        }
        cout << ans << endl;
    }

}


