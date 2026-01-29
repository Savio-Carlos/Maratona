#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin >> n;
    map<int,int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
        ans += (mp[x] % 2 == 0);
    }
    cout << ans/2 << endl;
}