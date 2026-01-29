#include <bits/stdc++.h>
using namespace std;

signed main(){
    string s, t;
    cin >> s >> t;

    int n  = s.size();
    int l = -1, r = 0;
    for (int i = 0; i < n; i++){
        if (s[i] != t[i] && l == -1) l = i;
        if (l != -1 && t[i] == s[l] && s[i] == t[l]){
            r = i;
        } 
    }
    
    if (l != -1)reverse(s.begin() + l, s.begin() + r + 1);
    if (s == t) cout << "YES\n";
    else cout << "NO" << endl;
}