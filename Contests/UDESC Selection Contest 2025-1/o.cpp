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
const int INF = LLONG_MAX;

int minw[MAX], answered[MAX];
vector<vector<pair<int,int>>> graph;

void djikstra(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    minw[0] = 0;
    while(!pq.empty()){
        auto [w,v] = pq.top();
        pq.pop();
        w = -w;
        if (minw[v] < w) continue;
        for (auto [peso, u] : graph[v]){
            int novomaximo = max(peso,w);
            if (minw[u] > novomaximo){
                minw[u] = novomaximo;
                pq.push({-novomaximo, u});
            }
        }
    }
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++){
        int fr, to, w;
        cin >> fr >> to >> w;
        graph[--fr].push_back({w,--to});
        graph[to].push_back({w,fr});
    }
    for (int i = 0; i < n; i++) minw[i] = INF;
    djikstra();
    minw[0] = 0;
    // for (int i = 0; i < n; i++){
    //     cout << i << " minimo: " << minw[i] << endl;
    // }
    int q;
    cin >> q;
    int ans = 0;
    multiset<int> stairs;
    vector<int> days(q);
    vector<pair<int,int>> queries;
    for (int &u : days){
        cin >> u;
        u--;
        if (!u) {ans++;continue;}
        else queries.push_back({minw[u],u});
    }
    for (int i = 0; i < q; i++){
        int a;
        cin >> a;
        stairs.insert(a);
    }
    sort(all(queries));
    for (auto [custo,destino] : queries){
        auto it = stairs.lower_bound(custo);
        if (it != stairs.end()){
            ans++;
            stairs.erase(it);
        }
    }
    cout << ans << endl;
}