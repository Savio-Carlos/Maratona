#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t, n, k, m;
    cin >> t;
    while (t--){
        cin >> n >> m >> k;
        for (int i = n; i >= k; i--){
            cout << i << " ";
        }
        for (int i = m+1; i < k; i++){
            cout << i << " ";
        }
        for (int i = 1; i <= m; i++){
            cout << i << " ";
        }
        cout << endl;
    }
}   
// n = 10; m = 3; k = 8;