#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while(t--){
        ll n, hp;
        cin >> n >> hp;
        vector<ll> atk (n+1);
        for (int i = 0; i < n; i++){
            cin >> atk[i];
        }

        atk[n]=LLONG_MAX;

        ll l = 0, r = 2e18+5;
        ll mid = 0, ans = -1;
        while (l<=r){
            mid = l + (r-l)/2;
            ll sum = 0;
            for (int i = 0; i < n; i++){
                if (atk[i]+mid > atk[i+1]){
                    sum += atk[i+1]-atk[i]; 
                }
                else {
                    sum += mid;
                
                }
            }

            if (sum >= hp){
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        cout << ans << endl;
    }
}