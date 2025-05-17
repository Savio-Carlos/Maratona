#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int INF = 1e9+7;

struct Edge {
    int to, cap;
};

class minBottleneck {
private:
    int n;
    vector<vector<Edge>> graph;
public:
    minBottleneck(int n) : n(n), graph(n){}

    void addEdge(int from, int to, int capacity) {
        graph[from].push_back({to, capacity});
    }

    int maximumBottleneckPath(int s, int e) {
        vector<int> maxCap (n,0);
        maxCap[s] = INT_MAX;
        priority_queue<pair<int,int>> pq;
        pq.push({maxCap[s], s});

        while (!pq.empty()){
            auto [cap, u] = pq.top();
            pq.pop();
            if (u == e) return cap;
            if (cap < maxCap[u]) continue;

            for (Edge &ed : graph[u]){
                int newCap = min(cap, ed.cap);
                if (newCap > maxCap[ed.to]){
                    maxCap[ed.to] = newCap;
                    pq.push({newCap, ed.to});
                }
            }
        }
        return 0;
    }
};

signed main() {
    winton
    int n, s, e, m; cin >> n >> m >> s >> e;
    s--; e--;
    minBottleneck G(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G.addEdge(a,b,c);
    }
    int ans = G.maximumBottleneckPath(s,e);
    if (ans == 0) cout << "-1" << endl;
    else cout << ans << endl;  
}