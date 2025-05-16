#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t, l, r, val, q, index, u;
    cin >> t;
    while (t--){
        cin >> n >> u;
        vector<int> arr(n+1, 0);
        while (u--){
            cin >> l >> r >> val;
            arr[l]+= val;
            arr[r+1]-=val;
        }
        for (int i = 1; i <= n; i++){
            arr[i] += arr[i-1];
        }
        cin >> q;
        while(q--) { 
            cin >> index;
            cout << arr[index] << endl;
        }
    }
}