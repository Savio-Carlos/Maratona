#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int INF = 1e18;

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for(auto &u : a){ cin >> u; mx = max(mx,u);}
    vector<int> ans1(n, INF), ans2(n, INF);


    vector<int> b = a;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (int i = 0; i < n; i++){
        while(!pq.empty() && pq.top().first < a[i]){
            auto [valor, idx] = pq.top();
            pq.pop();
            ans1[idx] = abs(idx - i);
        }
        pq.emplace(a[i], i);
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;

    for (int i = n-1; i >= 0; i--){
        while(!pq2.empty() && pq2.top().first < b[i]){
            auto [valor, idx] = pq2.top();
            pq2.pop();
            ans2[idx] = abs(idx - i);
        }
        pq2.emplace(a[i], i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == mx) continue;
        ans += min(ans1[i], ans2[i]);
        // cout << "ans1: " << ans1[i] << " ans2: " << ans2[i] << endl;  
    }
    cout << ans << endl;
}