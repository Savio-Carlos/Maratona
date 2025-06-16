#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 30;
const int INF = INT_MAX;

int n, visited[MAX], indeg[MAX];
vector<set<int>> graph(27);
vector<char> ans;
set<int> cycle;
bool pos = true;

void dfs(int v){
    visited[v] = 1;
    cycle.insert(v); 
    for (auto u : graph[v]){
        if(cycle.count(u)>0) pos = false;
        if (!visited[u])dfs(u);
    }
}

signed main(){
    winton;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < s.size()-1; j++){
            if(s[j] == s[j+1]) continue;
            int from = s[j] - 'a'+1, to = s[j+1] - 'a'+1;
            if (graph[from].count(to) == 0)indeg[to]++;
            graph[from].insert(to);
        }
    }
    queue<int> q;
    for (int i = 1; i <= 26; i++){
        if (indeg[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();   
        q.pop();
        ans.push_back(cur+'a'-1);
        for (auto u : graph[cur]){
            //cout << cur << " -> " << u << endl;
            indeg[u]--;
            if (indeg[u] == 0)q.push(u);
        }
    }
    for (int i = 1; i <= 26; i++){
       //cout << indeg[i] << " ";
       if (indeg[i] != 0) pos = false;
    }      

    if (pos){
        cout << "SIM" << endl;
        for (auto u : ans) cout << u;
        cout << endl;
    }
    else cout << "NAO" << endl;
}