#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
   
    while (t--) {
        ll n, mini = LLONG_MAX, mx = 0, sum = 0;
        cin >> n;
        vector<ll> riq(n);

        for (int i = 0; i < n; i++){
        cin >> riq[i];
        sum += riq[i];
        mx = max(mx, riq[i]);
        }
        double media = (sum)/n;

    ll l = 0;
    ll r = 2e18+5;
    ll ans = -1;

    while(l<=r){
        ll cnt = 0;
        ll pot = l+(r-l)/2;
        long double nsum = 0;
       
        riq[distance(riq.begin(),max_element(riq.begin(),riq.end()))] += pot;
        for (int i = 0; i < n; i++){
            nsum += riq[i];
        }
        long double nmedia = nsum/n;
        for (int i = 0; i < n; i++){
            if (riq[i] < nmedia/2) cnt++;
        }
        if (cnt>n/2) ans = pot;
        //cout << pot << " " << nmedia << endl;
       // cout << cnt << endl;
        riq[distance(riq.begin(),max_element(riq.begin(),riq.end()))] -= pot;
     
        if (cnt>(n/2)){
            r = pot-1;
        }
        else {
            l = pot+1;
        }
    }
    cout << ans << endl;
    }
}