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
vector<int> w, ans, cur;             

bool bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[a] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				if (i == n){
                    st = ar[j].first;
                    return 1;
                }
				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}
	return 0;
}

void check(int v){
    //debug(v);
    if (visited[v]){
        if (v == st){
            ans = cur;
        }
        return;
    }
    visited[v] = 1;
    for(auto [u,w] : graph[v]){
            cur.push_back(u);
        check(u);
        cur.pop_back();
    }
}

signed main(){
    winton;
    cin >> n >> m;
    ar.resize(m);
    w.resize(m);
    graph.resize(n);
    for (int i = 0; i < m; i++){
        cin >> ar[i].first >> ar[i].second >> w[i];
        ar[i].first--;
        ar[i].second--;
        graph[ar[i].first].push_back({ar[i].second, w[i]});
    }
    bool c = bellman_ford(0);
    //debug(st);
    if (c){
        check(st);
        cout << "YES" << endl;
        for (auto u : ans) cout << u+1 << " ";
        //cout << ans[0]+1 << endl;
        return 0;

    }
    else cout << "NO" << endl;
}