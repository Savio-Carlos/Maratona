#include <bits/stdc++.h>
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

template <typename T>int index(const vector<T> &vec, const T &n) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == n) { return i; }
	}
	return -1;
}

signed main() {
	setIO("gymnastics");
    int k, n, ans = 0;
    cin >> k >> n;
    vector<vector<int>> arr(k, vector<int>(n));

    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            arr[i][j]--;
        }
    }

    for (int c1 = 0; c1 < n; c1++){
        for (int c2 = 0; c2 < n; c2++){
            if (c1==c2) continue;
            bool melhor = true;
            for (const vector<int> &s : arr){
                if (index(s,c1) < index(s,c2)){
                    melhor = false;
                    break;
                }
            }
            ans += melhor;
        }
    }
    cout << ans << endl;
}