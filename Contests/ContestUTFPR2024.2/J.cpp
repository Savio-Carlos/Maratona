#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int INF = 1e9+7;

signed main() {
    vector<bool> visto (26,true);
    string s;
    cin >> s;
    string forca = s;
    for (int i = 0; i < s.size(); i++){
        forca[i] = '_';
        visto[s[i]-'a'] = false;
    }
    char c;
    while (cin >> c){
        if (c == '*') break;
        if (visto[c-'a']){
            cout << forca << endl;
            continue;
        }
        for (int i = 0; i <(int) s.size(); i++){
            if (c == s[i]){
                forca[i] = c;
            }
        }
        cout << forca << endl;
        visto[c-'a'] = true;
    }
    
}