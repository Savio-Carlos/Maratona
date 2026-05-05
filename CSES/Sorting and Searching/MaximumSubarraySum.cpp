#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    int mx = a[0], sum = 0;
    for (auto u : a){
        sum = max(sum + u, u);
        mx = max(mx, sum);
    }
    cout << mx << endl; 
}
