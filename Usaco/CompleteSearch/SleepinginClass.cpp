#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = LLONG_MAX;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
signed main() {
    //setIO("")
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<int> logs(n);
        int sum = 0, goal = 0;
        for (int i = 0; i < n; i++){
            cin >> logs[i];
            sum += logs[i];
        }
        for (int i = 0; i <= sum; i++){
            if (i != 0 && sum%i != 0){
                continue;
            }
            
            bool valid = true;
            int cur = 0;
            for (int &u : logs){
                cur += u;
                if (cur > i){
                    valid = false;
                    break;
                }
                else if (cur == i){
                    cur = 0;
                }
            }
            if (valid){
                if (i == 0){
                    cout << "0" << endl;
                }
                else cout << n - sum/i << endl;
                break;
            }
        } 
    }
}