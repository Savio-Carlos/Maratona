#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define winton ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

signed main(){
    winton;
    int n;
    cin >> n;
    map<int,int> cnt;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (auto [u,q] : cnt){
        if (cnt.count(u+1) )ans += q*cnt[u+1];
    }
    cout << ans << endl;
}