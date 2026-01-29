
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'
 
void solve(){
	string s, t; cin >> s >> t;
	map<char, int> lst;
	for(int i = 0; i < t.size(); i++) lst[t[i]]++;
 
	string res;
	for(int i = s.size()-1; i >= 0; i--){
		if(lst[s[i]]){
			lst[s[i]]--;
			res += s[i];
		}
	}
	reverse(res.begin(), res.end());
	if(res == t) cout << "YES\n";
	else cout << "NO\n";
}
 
signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}