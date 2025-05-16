#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int sum = 0;
        vector<int> a(n), pfx(n+1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 1; i <= n; i++) {
            pfx[i] = a[i-1];
            pfx[i] += pfx[i-1];
        }
        int l = 0, r = n-k, ans = 0;
        for (int i = 0; i < k; i++){
            int soma = pfx[r] - pfx[l];
            int soma2 = pfx[r+1] - pfx[l+2];
            soma = max(soma,soma2);
            ans = max(ans, soma);
            //cout << soma << " r= " << r << " l = "<< l <<  endl;
            //cout << pfx[l] << " " << pfx[r] << endl;
            l+=2;
            r++;
        }
        cout << ans << endl;
    }
}

/*
 for (int i = 0; i < k; i++){
            if (a[l] + a[l-1] < a[r]){
                sum -= (a[l] + a[l-1]);
                l+=2;
            }
            else {
                sum -= a[r];
                r--;
            }
        }
*/