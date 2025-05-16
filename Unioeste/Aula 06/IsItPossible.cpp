#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if (abs(n-m) %2 !=0){
            cout << "-1" << endl;
            continue;
        }
        else if (!n && !m){
            cout << "0 " << endl;
            continue;
        }
        else {
            
            if (n == m) {
                cout << "1 " << n << endl;
            }
            else {
                int meio = (n+m)/2;
                cout << "2 " << meio << " "<< n-meio << endl; 
            }
        }
        
    }
}