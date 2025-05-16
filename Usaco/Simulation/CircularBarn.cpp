#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = LLONG_MAX;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main() { _
	setIO("cbarn");
    int n; cin >> n; 
    vector<int> barn(n);
    int total = 0;
    for (auto &u : barn){
        cin >> u;
        total += u;
    }
    int ans = MAXL;
    for (int i = 0; i < n; i++){
        int cur = 0;
        int rest = total;
        for (int j = 0; j < n; j++){
            rest -= barn[(i+j)%n];
            cur += rest;
        }
        ans = min (ans, cur);
    }
    cout << ans << endl;


}