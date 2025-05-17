#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e4+1;
const int LOG = 20;
const int INF = INT_MAX;

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<int> ts(m), ans;
    int mnp = 1e4;
    for (int i = 0; i < m; i++) cin >> ts[i];

    for (int i = 1; i <= min(n,mnp); i++){
        ans.push_back(i);
    }
    for (int i = m-1; i>= 0; i--){
        for (int j = 0; j < ans.size(); j++){
            ans[j] += (ans[j]-1)/(ts[i]-1);
        }
        while (ans.back() > n) ans.pop_back();
    }
    for (int i : ans) cout << i << endl;
}