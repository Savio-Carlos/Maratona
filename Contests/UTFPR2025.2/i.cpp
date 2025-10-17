#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define endl '\n'

const int MAXN = 1e8+9;
int divi[MAXN];
set<int> primes;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.insert(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

signed main() {
    fastio;
    crivo(MAXN);
    // for (auto u : primes) cout << u << endl;
    int n; cin >> n;
    //vector<vector<int>> arrays;
    vector<int> somas(n, 0);
    for(int i = 0; i < n; i++){
        int m, x; cin >> m >> x;
        //cout << m << endl;
        for(int j = 2; j <= m; j++){
            cin >> x;
            //cout << primos[j] << " ";
            if(primes.find(j) != primes.end()) somas[i] += x;
            //v.push_back(x);
        }
        //cout << somas[i] << endl;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(primes.find(somas[i]) != primes.end()){
            ans.push_back(somas[i]);
        }
    }

    if(ans.empty()){
        cout << "ITS OVER SOBROU NADA PRO BETINHA\n";
        return 0;
    }
    cout << ans.size() << endl;
    for(auto u : ans) cout << u << " ";
    cout << endl;
} 