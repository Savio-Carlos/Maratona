#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

struct ponto {
    int x, y;
};

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        multiset<int> xs, ys;
        vector<ponto> points(n);
        for(auto &u : points) {
            cin >> u.x >> u.y;
            xs.insert(u.x);
            ys.insert(u.y);
        }
        if (n == 1) {cout << 1 << endl; continue;}
        int ans = LLONG_MAX;
        for(auto u : points) {
            auto it = xs.find(u.x);
            xs.erase(it);
            it = ys.find(u.y);
            ys.erase(it);

            int x1 = *xs.begin();
            int x2 = *xs.rbegin();
            int y1 = *ys.begin();
            int y2 = *ys.rbegin();

            int area = (x2-x1+1) * (y2-y1+1);
            //cout << "x1: " << x1 << " x2: " << x2 << " y1: " << y1 << " y2: " << y2 << endl;
            if (area == n-1) area+=min((x2-x1+1), (y2-y1+1));
            ans = min(ans,area);
            xs.insert(u.x);
            ys.insert(u.y);
        }
        cout << ans << endl;
    }
}