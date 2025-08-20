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
const int MAX = 100+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
int d[MAX];
vector<pair<int, int>> ar;
vector<int> w;             

bool bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[a] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				if (i == n) return 1;

				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}

	return 0;
}

signed main(){
    int s, t;
    cin >> n >> m >> s >> t;
    ar.resize(m);
    w.resize(m);
    for (int i = 0; i < m; i++){
        cin >> ar[i].first >> ar[i].second >> w[i];
        ar[i].first--;
        ar[i].second--;
    }
    vector<int> gain(n);
    for (int i = 0; i < n; i++){
        cin >> gain[i];

    for (int i = 0; i < m; i++){
        auto &[u,v] = ar[i];
        w[i] -= gain[v];
    }
    // for (int i = 0; i < m; i++){
    //     auto [u,v] = ar[i];
    //     cout << u << " -> " << v << " w: " << w[i] << endl;
    // }
    bool c = bellman_ford(--s);

    if (c) cout << "Money hack!" << endl;
    else if (d[t-1] == INF) cout << "Bad trip" << endl;
    else cout << -d[t-1] << endl;
}