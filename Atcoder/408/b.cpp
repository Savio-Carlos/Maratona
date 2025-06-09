#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n;
    cin >> n;
    int cnt = n;
    set<int> ans;   
    while(n--){
        int x;
        cin >> x;
        ans.insert(x);
    }
    cout << ans.size() << endl;
    for (auto u : ans) {
        cout << u << " ";
    
    }
}