#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 1e6+7;
const int INF = LLONG_MAX;

int visited[MAX];

void solve(){
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    vector<int> tree;
    for (int i = n; i >= 1; i--){
        visited[i] = 0;
        if (i + (n-cnt-1) <= m){
            tree.push_back(i);
            cnt++;
            m-=i;
            visited[i] = 1;
        }
    }
    m -= (n-cnt);
    if (m != 0){
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]) tree.push_back(i);
    }
    cout << tree[0] << endl;
    for (int i = 1; i < n; i++){
        cout << tree[i-1] << " " << tree[i] << endl;
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}