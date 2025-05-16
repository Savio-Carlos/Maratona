#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
    ll t, n, mini = LLONG_MAX;
    cin >> n >> t;
    vector<ll> tempos(n);

    for (int i = 0; i < n; i++){
        cin >> tempos[i];
        mini = min(mini, tempos[i]);
    }

    ll l = 0;
    ll r = t*mini;
    ll ans = 0;

    while(l<=r){
        ll mid = l + (r-l)/2;
        ll sum = 0;
        for (int i = 0; i < n; i++){
            sum+=(mid/tempos[i]);
            if (sum >= t) break;
        }

        if (sum>=t){
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    cout << ans << endl;
}