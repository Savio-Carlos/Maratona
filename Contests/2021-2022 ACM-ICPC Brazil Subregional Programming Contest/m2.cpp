#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 1e5+7;
const int INF = INT_MAX;

int morreu[MAX];
vector<int> graph [MAX];
vector<int> euler;

void dfs(int v, int p){
    euler.push_back(v);
    for (auto u : graph[v]){
        if (u == p) continue;
        dfs(u,v);
    }
}

signed main(){
    int q;
    cin >> q;
    int id = 2;
    vector<int> queries;
    while(q--){
        int tp; cin >> tp;
        if (tp == 1){
            int p; cin >> p;    
            graph[p].push_back(id++);
            graph[id].push_back(p);
        }
        else {
            int p; cin >> p; 
            queries.push_back(p);
        }
    }
    dfs(1,-1);
    int cur = 0;
    for (auto u : queries){
        morreu[u] = 1;
        while (morreu[euler[cur]]) cur++;
        cout << euler[cur] << endl;
    }
}