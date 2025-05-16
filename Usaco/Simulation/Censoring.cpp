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

signed main() {_
	setIO("censor");
    string s, t;
    cin >> s >> t;
    string ns;
    for (int i = 0; i < s.size(); i++){
        ns += s[i];
        if (ns.size() > t.size()){
            string temp = ns.substr(ns.size()-t.size(), t.size());
            if (temp == t){
                ns.erase(ns.size()-t.size());
            }
        }
    }
    cout << ns << endl;
}