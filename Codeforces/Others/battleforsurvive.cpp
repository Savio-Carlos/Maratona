#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        vector<ll> arr (n);
        
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
  
        ll sum = 0; 
        for (int i = 0; i < n-2; i++){
            sum += arr[n-2] - arr[i];
            arr[n-2] = sum;
            sum = 0;
        }
        cout << arr[n-1]-arr[n-2] << endl;
    }
}