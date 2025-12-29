#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

signed main(){
    fastio;
    string s; cin >> s;
    int cnt = 0, st = 0;
    string copy;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt == 0){
            copy = s.substr(0, i+1);
            st = i+1;
            break;
        }
    }
    // cout << "copy: " << copy << endl;
    for (int i = st; i < s.size(); i += st){
        if (s.size() - i < copy.size()){
            cout << s.substr(st) << copy << endl;
            return 0;
        }
        for (int j = 0; j < copy.size(); j++){
            if (s[i+j] != copy[j]){
                cout << s.substr(st) << copy << endl;
                return 0;
            }
        }
    }
    cout << "no\n";
}