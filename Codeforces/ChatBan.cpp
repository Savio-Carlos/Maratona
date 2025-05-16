#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define ld long double
const int MAXL = 1e5+7;

int pa(int n, int a, int b){
    return n*(a+b)/2;
}

signed main() {_
    int t; cin >> t;
    while(t--){
        ld k, x;
        cin >> k >> x;
        ld totc =  pow(k,2);
        ld totl = (2*k)-1;

        int l = 0; r = totl;
        while (l <= r){
            int mid = l + ((r-l)/2);
            int cur;
            if (mid <= k){
                cur = pa(mid,mid,1);
            }
            else {
                cur = pa(k,k,1) + pa(mid-k, k-1, k-(mid-k));
            }
            //mid representa a linha, entao calcula-se a quantidade de emotes ate aquela linha
            //se mid < k, entao e uma pa ate mid
            //se mid > k, entao e uma pa ate k + pareversa ate k-mid
            if (cur > x){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
    }   
}