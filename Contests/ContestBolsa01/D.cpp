#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXL = 1e9+7;

signed main(){_
    int n; cin >> n;
    n*=2;
    vi pizza(n);
    for (auto &i : pizza) cin >> i;
    sort(all(pizza));
    int ans = 0;
    for (int i = 0; i < n; i+=2){
        ans += max(pizza[i], pizza[i+1]);
    }
    cout << ans << endl;
}