#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXL = 1e9+7;

int sumE (int r, int e){
    int sum = 1, cur = 1;
    for (int i = 1; i <= e; i++) {
        if (cur > LLONG_MAX / r) return LLONG_MAX;
        cur *= r;
        if (sum > LLONG_MAX - cur) return LLONG_MAX;
        sum += cur;
    }
    return sum;
}

signed main(){_
    int n; cin >> n;
    vi divisores;
    for (int i = 1; i <= sqrt(n); i++){
        if (n%i == 0){
            divisores.pb(i);
            if (i != n/i) divisores.pb(n/i);
        }
    }
    int ans = 0;

    sort(all(divisores));
    
    for(auto u : divisores){
        int d = n/u;
        if (d == 1)ans++;
        else {
            for (int e = 1; e <= 30; e++) {
            int mini =  (1LL << (e + 1)) - 1;
            if (mini > d) continue;

            int l = 2, r = d;
            bool found = false;

            while (l <= r) {
                    int mid = l + (r-l)/2;
                    int sum = sumE(mid, e);

                    if (sum == d) {
                        found = true;
                        break;
                    } else if (sum < d) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (found)ans++;
            }  
        } 
    }
    cout << ans << endl;
}