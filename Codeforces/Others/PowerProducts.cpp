#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

int n, k, spf[MAX];
 map<map<int,int>, int> mp;

void build(){
    for (int i = 2; i <= MAX; i+=2) spf[i] = 2;
    for (int i = 3; i <= MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i <= MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

map<int,int> factorize(int x){
    map<int,int> cur;
    while (x > 1){
        int p = spf[x];
        int cnt = 0;
        while(x%p == 0){
            x/=p;
            cnt++;
        } 
        if (cnt % k != 0) cur[p] = cnt%k;
    }
    //for (auto u : cur) cout << u.first << " " << u.second << endl;
    //cout << endl;
    return cur;
}

signed main(){
    winton;
    cin >> n >> k;
    build();
    vector<int> a(n); 
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        map<int,int> form = factorize(a[i]);
        map<int,int> goal;
        for (auto const& [u,v] : form) {
            goal[u] = k - v ;
        }
        ans += mp[goal];
        mp[form]++;
    }
    cout << ans << endl;
}