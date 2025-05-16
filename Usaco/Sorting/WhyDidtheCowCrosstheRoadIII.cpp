#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main() {
	setIO("cowqueue");
    int n;
    cin >> n;
    vector<pair<int,int>> cows(n);
    for (auto &[a,b] : cows) {
        cin >> a >> b;
    }
    sort(all(cows));
    int cur = 0;
    for (auto [arrival,duration] : cows) {
        if (cur < arrival){
            cur += (arrival-cur) + duration;
        }
        else {
            cur += duration;
        }
       // cout << "current time : " << cur << endl;
    }  
    cout << cur << endl;
}   