#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n, sum = 0;
        cin >> n;
        vector<int> arr(n);
        int ans = 1;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            sum+=arr[i];
        }
        if (sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }
        int o = sum/n;

        for (int i = 1; i < n-1; i++){
            if (arr[i-1] < o){
                int temp = o-arr[i-1];
                 arr[i-1] =o;
                arr[i+1] -= temp;
            } 
            else if (arr[i-1] > o){
                int temp = arr[i-1]-o;
                arr[i-1] =o;
                arr[i+1] += temp;
            }
        }

         for (int i = 0; i < n-1; i++){
            if (arr[i] != arr[i+1]){
                ans = false;
                break;
            }
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}