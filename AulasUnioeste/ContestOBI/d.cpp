#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 505;
const int INF = INT_MAX;

signed main(){
    winton;
    string s, t;
    cin >> s >> t;
    vector<int> a1(26);
    vector<int> a2(26);
    int c = 0;
    for(int i = 0; i < s.size(); i++){
        a1[s[i]-'a']++;
        if (t[i] == '*')c++;
        else a2[t[i]-'a']++;
    }    
    bool ans = true;
    for (int i = 0; i < 26; i++){
        int diff = abs(a1[i] - a2[i]);
        c-=diff;
    }
    if (c != 0) cout << "N" << endl;
    else cout << "S" << endl;
}
