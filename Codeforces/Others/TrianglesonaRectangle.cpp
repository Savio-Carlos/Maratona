#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h;
        int kx0, kxw, ky0, kyh;
        vector<int> x0, xw, y0, yh;

        cin >> kx0;
        for (int i = 0; i < kx0; i++){
            int a; cin >> a;
            x0.push_back(a);
        }

        cin >> kxw;
        for (int i = 0; i < kxw; i++){
            int a; cin >> a;
            xw.push_back(a);
        }

        cin >> ky0;
        for (int i = 0; i < ky0; i++){
            int a; cin >> a;
            y0.push_back(a);
        }

        cin >> kyh;
        for (int i = 0; i < kyh; i++){
            int a; cin >> a;
            yh.push_back(a);
        }

        int ans = 0;
        for (auto &u : x0){
            int base = xw[kxw-1] - xw[0];
            
                int area = base*h;
                ans = max(ans,area);
        }
        //cout << ans << endl;
        for (auto &u : xw){
            int base = x0[kx0-1] - x0[0];
          
                int area = base*h;
                ans = max(ans,area);
            
        }
        //cout << ans << endl;
        for (auto &u : y0){
            int base = yh[kyh-1] - yh[0];
           
                int area = base*w;
                ans = max(ans,area);
            
        }
        //cout << ans << endl;
        for (auto &u : yh){
            int base = y0[ky0-1] - y0[0];
            
                int area = base*w;
                ans = max(ans,area);
            
        }
        cout << ans << endl;
    }
}