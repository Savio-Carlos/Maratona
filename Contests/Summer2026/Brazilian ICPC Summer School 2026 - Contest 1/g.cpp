#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() {cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

// #define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (auto &[pos, fuel] : a) cin >> pos >> fuel;
    int tot, tank;
    cin >> tot >> tank;
    for (auto &[pos,fuel] : a) pos = tot - pos;
    sort(all(a));
    a.push_back({tot, 0});
    debug(a);


    int ans = 1e9;
    int cnt = 0;
    priority_queue<int> pq;
    for (int i = 0; i <= n; i++){
        while (!pq.empty() && tank < a[i].first){
            tank += pq.top();
            cnt++;
            pq.pop();
        }
        if(a[i].first <= tank) pq.push(a[i].second);
        else{
            cout << "-1\n";
            return;
        }
    }
    if (tank < tot) cout << "-1\n";
    else cout << cnt << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--) solve();
}