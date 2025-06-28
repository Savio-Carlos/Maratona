#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

int visited[MAX], depth[MAX], ancestor[MAX];
vector<vector<int>> graph;

signed main(){
    winton;
    int n;
    cin >> n;
    graph.resize(n+1);
    for (int i = 0; i < n-1; i++){
        int a , b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> seq(n);
    for (auto &i : seq) cin >> i;
    if (seq[0] != 1) {
        cout << "No" << endl;
        return 0;
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        visited[v] = 1;
        for (auto u : graph[v]){
            if (!visited[u]){
                depth[u] = depth[u] + 1;
                ancestor[u] = v;
                q.push(u);
            }
        }
    }
    vector<int> prof(n + 1);
    for (int i = 0; i < n; ++i) {
        prof[seq[i]] = i;
    }
    bool pos = true;
    for (int i = 1; i < n; ++i) {
        int prev = seq[i - 1];
        int cur = seq[i];
        if (depth[cur] < depth[prev]) {
            pos = false;
            break;
        }
        if (depth[cur] == depth[prev]) {
            if (prof[ancestor[cur]] < prof[ancestor[prev]]) {
                pos = false;
                break;
            }
        }
    }
    if (pos) cout << "Yes" << endl;
    else cout << "No" << endl;
}