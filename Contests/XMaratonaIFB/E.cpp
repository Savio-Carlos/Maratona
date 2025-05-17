#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;

signed main() {
    winton;
    int n,m;
    cin>>n>>m;
    set<int> ans;
    for (int i = 0;i < n; i++){
        int a;
        cin >> a;
        ans.insert(a);
    }
    for (int i = 0;i < m; i++){
        int a;
        cin >> a;
        ans.insert(a);  
    }
    for(auto u : ans) cout << u << " ";
}