#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--){
        bool ans = true;
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        

        for (int i = 0; i < n-2; i++){
            int op = arr[i];
            arr[i] -= op;
            arr[i+1] -= op*2;
            arr[i+2] -= op;
            if (arr[i] < 0 ||arr[i+1] < 0||arr[i+2]< 0) ans = false;
        }

        for (int i = 0; i < n; i++){
            if (arr[i]!=0) ans = false;
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
}