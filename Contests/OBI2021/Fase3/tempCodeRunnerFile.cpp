#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e4+7;
const int LOG = 20;
const int INF = INT_MAX;

vector<vector<int>> graph;
int depth[MAXN], visited[MAXN], cnt[MAXN];

pair<int,int> dfs(int v){//first = profundidade, second = quantidade naquela profundidade
    visited[v] = 1;
    vector<pair<int,int>> sons = {{0,1}};

    for (auto u : graph[v]){
        if (!visited[u]){
            sons.push_back(dfs(u));
        }
    }
    int ff = 0, ss = 0;
	for(int i = 0; i < sons.size(); i++){
		if(sons[i] > sons[ff]) ss = ff, ff = i;
		else if(sons[i] > sons[ss]) ss = i;
    }

    vector<pair<int,int>> aux;
    for(int i = 0; i < sons.size(); i++){
        if(sons[i] == sons[ss]) aux.push_back(sons[i]);
    }
		
	if(sons[ff] == sons[ss]) {
		int foi = 0, ans = 0;
		for(int i = 0; i < aux.size(); i++){
            ans += foi * aux[i].first, foi += aux[i].first;
        }
			

		cnt[2*sons[ff].second + 1] += ans;
		
		return {sons[ff].second + 1, foi};
	}
	int ans = 0;

	for(int i = 0; i < aux.size(); i++){
        ans += sons[ff].first * aux[i].first;
    }

	cnt[sons[ff].second + sons[ss].second + 1] += ans;

	return {sons[ff].second + 1, sons[ff].first};

}

signed main () {
    winton;
    int n;
    cin >> n;
    graph.resize(n+1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    pair<int,int> ans = dfs(1);
    for(int i = MAXN-1; i >= 0; i--){
        if (cnt[i] > ans.first){
            ans.second = cnt[i];
            ans.first = i;
        }
    }   
}
