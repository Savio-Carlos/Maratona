#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
int n; cin >> n;
vector<int> a(n);
map<int,int> mp;
int ans = 0;
for (int i = 0 ; i < n; i++){
int x;
cin >> x;
mp[x-i]+=x;
ans = max(ans, mp[x-i]);
}
cout << ans << endl;
return 0;
}