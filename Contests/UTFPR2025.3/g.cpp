#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

signed main(){
    fastio;
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for(auto &u : a)cin>>u;
    int sum = 0;
    sort(all(a));
    int ans = -1;
    for (int i = 0; i < k; i++){
        sum += a[i];
    }
    if (sum > d){
        cout << "Nao e possivel" << endl;
    }
    else cout << sum << endl;
}