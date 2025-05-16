#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int LOG = 20;

int arr[MAX], answers[MAX];
vector<vector<int>>graph;
vector<set<int>> sexo(MAX);

void dfs(int v, int p){
    sexo[v].insert(arr[v]);
    for (auto u : graph[v]){
        if (u!=p){
            dfs(u, v);
            if(sexo[u].size() > sexo[v].size()) swap(sexo[u],sexo[v]);
            for (auto i : sexo[u]) sexo[v].insert(i);
        }
    }
    answers[v] = sexo[v].size();
}

signed main() {
    winton;
    int n;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,0);
    for (int i = 0; i < n; i++){
        cout << answers[i] << " ";
    }
}