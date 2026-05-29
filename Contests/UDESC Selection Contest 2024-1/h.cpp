#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    template<class A, class B> ostream& operator<<(ostream& o, const pair<A,B>& p) {
        return o << '(' << p.first << ", " << p.second << ')';
    }
    template<class T, class = enable_if_t<!is_same_v<T,string> && !is_same_v<T,string_view>>>
    auto operator<<(ostream& o, const T& v) -> decltype(v.begin(), o) {
        o << '{'; bool f = 1;
        for (auto& x : v) { o << (f ? "" : ", ") << x; f = 0; }
        return o << '}';
    }
    void out(string_view) { cerr << '\n'; }
    template<class H, class... T> void out(string_view s, H h, T... t) {
        auto c = s.find(',');
        cerr << s.substr(0, c) << " = " << h;
        if constexpr (sizeof...(t)) {
            cerr << " | ";
            out(s.substr(s.find_first_not_of(" ,", c)), t...);
        } 
        else cerr << '\n';
    }
}
using namespace dbg;

// #define DEBUG

#ifdef DEBUG
    #define winton (void)0
    #define debug(...) cerr << "[" << __LINE__ << "] ", out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 3e5+7;

int n, m, k;
vector<pair<int,int>> graph[MAX];
int dist[MAX];

bool djikstra(int mid){
    for (int i = 0; i <= n; i++) dist[i] = 1e18;
    
    deque<int> dq;
    dist[1] = 0;
    dq.push_front(1);

    while(!dq.empty()){
        auto v = dq.front();
        dq.pop_front();

        if (v == n) return (dist[n] <= k);

        for (auto [u,w] : graph[v]){
            int cost = (w > mid ? 1 : 0);

            if (dist[v] + cost < dist[u]){
                dist[u] = dist[v] + cost;

                if (cost == 1) dq.push_back(u);
                else dq.push_front(u);
            }
        }
    }
    // debug(mid, dist[n]); 
    return (dist[n] <= k);
}

signed main(){
    winton;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int ans = 0;
    int l = 0, r = 1e18;
    while(l <= r){
        int mid = l + (r-l)/2;

        if (djikstra(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}