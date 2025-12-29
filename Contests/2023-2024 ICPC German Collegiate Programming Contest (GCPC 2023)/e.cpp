#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)


signed main(){
    fastio;
    string s;
    cin >> s;

    vector<string> ans;

    for (int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }

    for (int i = 0; i < s.size()-1; i++){
        if (s[i] == 's' && s[i+1] == 's'){
            string op = s;
            op[i] = 'B';
            op.erase(i+1, 1);
            ans.push_back(op);
        }
    }
    ans.push_back(s);
    for (auto u : ans) cout << u << endl;
}