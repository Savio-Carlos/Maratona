#include <bits/stdc++.h>
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

signed main() {
	setIO("cownomics");
    int n, m; 
    cin >> n >> m;
    char spotty[n][m];
    char plain[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> spotty[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> plain[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++){
        map<char,bool> sp;
        map<char,bool> pl;
        for (int j = 0; j < n; j++){
            sp[spotty[j][i]] = true;
            pl[plain[j][i]] = true;
        }
        bool notequal = true;
        for (char g : {'A', 'C', 'G', 'T'}){
            if (sp[g] && pl[g]) notequal = false;
        }
        ans += notequal;
    }
    cout << ans << endl;
}