#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define winton ios_base::sync_with_stdio(0),cin.tie(0)

void solve(){
    string s; 
    cin >> s;
    int n = s.size();
    int sum = 0;
    for(auto c : s){
        sum += (c -'0');
    }
    int last = s[n-1]-'0';
    int pos = 0;
    vector<int> ans;
    if(last % 2 == 0) ans.push_back(2);
    if(sum % 3 == 0) ans.push_back(3);
    if(n > 1 && !(((s[n-2]-'0') * 10 + last) % 4)) ans.push_back(4);
    else if(n == 1 && (last % 4) == 0) ans.push_back(4);
    if(last == 0 || last == 5) ans.push_back(5);
    if(!(last % 2) && !(sum % 3)) ans.push_back(6);

    if(!ans.size()) cout << -1 << endl;
    else{
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i+1 == ans.size()];
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}   