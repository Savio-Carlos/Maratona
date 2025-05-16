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

signed main() {
	setIO("blocks");
    int n; cin >> n;
    vector<int> ans (26);

    for (int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        vector<int> str1(26);
        vector<int> str2(26);

        for (char c : a){
            str1[c-'a']++;
        }
        for (char c : b){
            str2[c-'a']++;
        }
        for (int j = 0; j < 26; j++){
            ans[j] += max(str1[j], str2[j]);
        }

    }
    for (auto i : ans){
        cout << i << endl;
    }
}