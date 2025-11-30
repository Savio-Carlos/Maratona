#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

const int MAXN = 1e5+7;
int spf[MAXN], pf[MAXN];

void build(){
    spf[1] = 1;
    for(int i = 2; i < MAXN; i += 2) spf[i] = 2;

    for(int i = 3; i < MAXN; i += 2){
        if(spf[i] == 0){
            spf[i] = i;
            for(int j = i; j*i < MAXN; j += 2){
                if(spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n];
    build();
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        int x = arr[i];
        int prev = -1;
        while(x > 1){
            int p = spf[x];
            mp[p]++;
            while(!(x%p)) x/=p;
        }
    }

    int ans = 1;
    for(auto [a, b] : mp) ans = max(ans, b);
    cout << ans << endl;
    
}