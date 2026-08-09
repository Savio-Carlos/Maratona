#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

signed main(){
    winton;
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    
    if (t >= k){
        cout << -1 << endl;
        return 0;
    }
    
    int sum = accumulate(all(a), 0LL);
    int tot = a.back() * n - sum;
    int best = 0;
    map<int,int> lazy;
    tuple<int,int,int> ans = {-1,0,0};
    for (int i = 0; i < n; i++){
        auto it = lower_bound(all(a), a[i] + k);
        int r = *(prev(it));

        lazy[a[i]] = i+1;
        int cur = r - a[i];
        int save = ((cur * (i+1)) - t * (i+1));
        if (save > best){
            ans = {i+1, r, tot - save};
            best = save;
        } 


    }

    auto &[i,j,c] = ans;
    cout << i << " " << lazy[j] << " " << c << endl; 
}