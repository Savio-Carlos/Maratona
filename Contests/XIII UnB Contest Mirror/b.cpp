#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    string s;
    cin >> s;
    int cnt = 0;
    string ans1, ans2;
    for (int i = 1; i < s.size(); i++){
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, s.size()-i);
        // cout << s1 << " " << s2 << endl;
        int a = stoll(s1);
        int b = stoll(s2);

        if (s1[0] != '0' && s2[0] != '0' && a < 100 && b < 100){
            cnt++;
            ans1 = s1;
            ans2 = s2;
        } 
    }
    if (cnt == 1){
        cout << ans1 << " " << ans2 << endl;
    }
    else cout << "-1\n";
}
