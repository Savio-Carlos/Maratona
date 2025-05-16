#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;  
        vector<ll> arr (n);
        vector<ll> brr (n+2);

        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int m = n/2;
        for (int i = 1; i <= m; i++){
           brr[i*2-1] = arr[i-1];
           brr[i*2] = arr[i+m-1];
        }
        brr[0] = brr[n];
        brr[n+1] = brr[1];

        bool ans = true;
        for (int i = 1; i <= n; i++){
            if (!(brr[i] < brr[i-1] && brr[i] < brr[i+1]) && !(brr[i] > brr[i+1] && brr[i] > brr[i-1])){
                ans = false;
            }
        }
        if (ans){
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++){
            cout << brr[i] << " ";
        }
        cout << endl;
        }
        else cout << "NO" << endl;


    }

}