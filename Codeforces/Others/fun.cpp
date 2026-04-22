#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll comb (int n){
    return (n * (n + 1)) / 2;
}

int main() {
    int t; cin >> t;
    while(t--){
        ll n, x, ans = 0;
        cin >> n >> x;
        int k = min(n,x);

        for (int a = 1; a<=k; a++){
            for (int b = 1; a*b <= n && a+b<=x; b++){
                int C = min((n-a*b)/(a+b),x-(a+b));
                ans+=C;
                //cout << "("<<a<<','<<b<<','<<C<<")"<< endl;
            }
        }
        cout << ans << endl;
    }
}