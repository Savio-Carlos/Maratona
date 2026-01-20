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

struct poster {
    int l, r, id;
};


void solve() {
    int n;
    cin >> n;
    vector<poster> posters(n);
    vector<int> points;
    
    for(int i = 0; i < n; ++i) {
        cin >> posters[i].l >> posters[i].r;
        posters[i].id = i;
        points.push_back(posters[i].l);
        points.push_back(posters[i].r + 1);
    }
    
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    
    sort(posters.begin(), posters.end(), [](const poster& a, const poster& b) {
        return a.l < b.l;
    });
    
    priority_queue<pair<int,int>> pq;
    set<int> visible;
    
    int poster_idx = 0;
    
    for(int i = 0; i < points.size() - 1; i++) {
        int cur = points[i];

        while(poster_idx < n && posters[poster_idx].l == cur) {
            pq.push({posters[poster_idx].id, posters[poster_idx].r + 1});
            poster_idx++;
        }
        while(!pq.empty() && pq.top().second <= cur) pq.pop();

        if(!pq.empty()) visible.insert(pq.top().first);
    }
    
    cout << visible.size() << endl;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while(t--) solve();

}

