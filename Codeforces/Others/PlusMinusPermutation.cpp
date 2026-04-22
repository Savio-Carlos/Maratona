#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

int pa(int n, int a, int b){
    return n*(a+b)/2;
}

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        int mmc = lcm(x,y);
        int p1 = n/x, p2 = n/y, ans = 0;
        int overlap = n/mmc;
        p1-=overlap;
        p2-=overlap;
        ans = pa(p1,n,n-p1+1) - pa(p2,p2, 1);
        cout << ans << endl;
    }   
}