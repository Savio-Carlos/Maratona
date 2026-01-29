#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)

bool check(char c){
    return (c >= '0' && c <= '9');
}

signed main(){
    winton;
    string s;
    cin >> s;
    int i = 0;
    string ans = "";
    while (i < s.size() && (s[i] >= '0' && s[i] <= '9')) {
        ans += s[i];
        i++;
    }

    cout << (ans.size() == 0 ? "-1" : ans) << endl;
}