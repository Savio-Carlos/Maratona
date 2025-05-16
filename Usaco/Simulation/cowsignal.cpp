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
	setIO("cowsignal");
	int m, n, k; 
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++){
		string s;
		cin >> s;
		for(int j = 0; j < k; j++){
			for (char c : s){
				for (int l = 0; l < k; l++){
					cout << c;
				}
			}
			cout << endl;
		}
	}
}