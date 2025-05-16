#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> graph;
vector<int> visited;
vector<int> ans;
int cnt;
string s;

int dfs(int v, int comeco){
    if (s[v-1] == '0') cnt++; 
    visited[v] = 1;
    if (graph[v] == comeco) return ans[v] = cnt;
    
    if(visited[graph[v]]) return ans[v];
    if(!visited[graph[v]]) return ans[v]+=dfs(graph[v],comeco);

}

int main() {
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;

        graph.resize(n+1);
        ans.resize(n+1);
        visited.resize(n+1);

        for (int i = 1; i <= n; i ++){
            ans[i] = 0;
            visited[i] = 0;
            cin >> graph[i];
        }
        cin >> s;
        
        for (int i = 1; i <= n; i ++){
            cnt = 0;
            dfs(i,i);
        }
            for (int i = 1; i <= n; i ++){
                cout << ans[i] << " ";
        }

        cout << endl;
    }

}   