#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2500+7;
const int INF = 1e18;

int n, m, st;
int d[MAX], visited[MAX];
vector<pair<int, int>> ar;
vector<vector<pair<int,int>>> graph;
vector<int> w, ancestor;             

bool bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[a] = 0;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j < m; j++) {
            auto [v,u] = ar[j];
			if (d[u] > d[v] + w[j]) {
				if (i == n){
                    st = v;
                    return 1;
                }
                ancestor[u] = v;
				d[u] = d[v] + w[j];
			}
		}
    }
	return 0;
}

signed main(){
    winton;
    cin >> n >> m;
    ar.resize(m);
    w.resize(m);
    graph.resize(n);
    ancestor.resize(n);
    for (int i = 0; i < m; i++){
        cin >> ar[i].first >> ar[i].second >> w[i];
        ar[i].first--;
        ar[i].second--;
        graph[ar[i].first].push_back({ar[i].second, w[i]});
    }
    bool c = bellman_ford(0);
    //debug(st);
    if (c){
        for (int i = 0; i < n; i++) st = ancestor[st];
        vector<int> ans;
        int cur = st;
        do {
            ans.push_back(cur);
            cur = ancestor[cur];
        } while (cur != st);
        ans.push_back(st);     

        reverse(ans.begin(), ans.end());

        cout << "YES" << endl;
        for (int u : ans) cout << u+1 << " ";
        cout << endl;
    }
    else cout << "NO" << endl;
}