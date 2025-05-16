#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main() { _
	//setIO("speeding");
    int n, m; cin >> n >> m;

    vector<pair<int,int>> segments (n);
    vector<pair<int,int>> bessie (n);
    for (int i = 0; i < n; i++){
        int seg, speed;
        cin >> seg >> speed;
        segments[i].second = speed;
        segments[i].first = seg;
        if (i > 0) segments[i].first += segments[i-1].first;
    }
    for (int i = 0; i < m; i++){
        int seg, speed;
        cin >> seg >> speed;
        bessie[i].second = speed;
        bessie[i].first = seg;
        if (i > 0) bessie[i].first += bessie[i-1].first;
    }
    int ans = 0;
    int j = 0;

    for (int i = 0; i < n; i++){
        while(bessie[j].first <= segments[i].second) j++;
        ans = max(ans, bessie[j].second - segments[i].second);
    } 
    cout << ans << endl;
}