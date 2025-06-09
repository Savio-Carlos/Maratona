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

char arr[MAX];
vector<vector<int>> graph;
vector<set<string>> sexo;
set<string> f;

void dfs(int v, int p, string cur){
    cout << p << " -> " << v << endl;
    cout << cur << endl;
    f.insert(cur);
    for (auto u : graph[v]){
        if (u == p) continue;
        string novo = cur;
        novo += arr[v];
        dfs(u,v,novo);
        //if (sexo[u].size() > sexo[v].size()) swap(sexo[u], sexo[v]);
    }
}

signed main(){
    //winton;
    int n;
    cin >> n;
    graph.resize(n+1);
    sexo.resize(n+1);
    for (int i = 1; i <= n-1; i++){
        int a;
        cin >> a;
        graph[a].push_back(i+1);
        graph[i+1].push_back(a);
    }
    for (int v = 1; v <= n; v++){
        cout << v <<": ";
        for (auto u : graph[v]){
            cout << u << " ";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++){
        cin >> arr[i];
    }
    dfs(1,0, "");
    for (auto u : f) cout << u << endl;
}