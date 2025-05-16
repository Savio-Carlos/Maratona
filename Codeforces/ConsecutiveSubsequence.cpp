#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for (auto &u : a) cin >> u;
    int ans = 0, lst;
    for (int i = 0; i < n; i++){
        mp[a[i]] = mp[a[i]-1]+1;
        if (mp[a[i]] > ans) {
            ans = mp[a[i]];
            lst = a[i];
        }
    }
    vector<int> res;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == lst) {
			res.push_back(i+1);
			--lst;
		}
	}
    reverse(all(res));
    cout << res.size() << endl;
    for (auto u : res) cout << u << " ";
    //for (auto u : mp) cout << u.first << " " << u.second << endl;
}