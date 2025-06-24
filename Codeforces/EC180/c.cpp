#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = LLONG_MAX;

void solve(){
	int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int cnt = 0;
    for(int i = 2; i < n; i++){
        int maxi = max(a[n-1] - a[i], a[i]);
        int l = 0;
        int r = i-1;
        while(l < r){
            if(a[r] + a[l] > maxi){
                cnt += r-l;
                r--;
            }
            else l++;
        }
    }
    cout << cnt << endl;
}
   
signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}