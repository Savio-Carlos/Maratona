#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    string s; cin >> s;
    int v = 0;
    int n = s.size();
    for(int i = 0; i < s.size(); i++){
        v += (s[i] -'0');
    }
    int k = s[n-1]-'0';
    int pos = 0;
    vector<int> ans;
    if(!(k%2)) ans.push_back(2);
    if(!(v%3)) ans.push_back(3);
    if(n > 1 && !(((s[n-2]-'0')*10 + k)%4)) ans.push_back(4);
    else if(n == 1 && !(k%4)) ans.push_back(4);
    if(k == 0 || k == 5) ans.push_back(5);
    if(!(k%2) && !(v%3)) ans.push_back(6);

    if(!ans.size()) cout << -1 << endl;
    else{
        for(int i = 0; i < ans.size(); i++){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}