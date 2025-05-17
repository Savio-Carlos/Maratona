#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    vector<int> q(26,0);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++){
        q[s[i]-'a']++;
    }
    sort(q.begin(), q.end());

    int ans = 0;
    for (int i = 0; i < 24; i++){
        ans += q[i];
    }
    cout << ans << endl;
}