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

void solve(){
    int n, m;
    cin >> n >> m;
    deque<int> a(m);
    for (auto &u : a)cin >> u;
    sort(all(a));
    for (int i = 0; i < n; i++){
        if(i&1){
            cout << a.front() << " " << a.back() << " " << a.front() << " " << a.back() << " " << a.front() << " " << a.back() << endl;
        }
        else {
            cout << a.back() << " " << a.front() << " " << a.back() << " " << a.front() << " " << a.back() << " " << a.front() << endl;
        }
        if (i >= 1 && i%2){
            a.pop_back();
            a.pop_front();
        }
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}