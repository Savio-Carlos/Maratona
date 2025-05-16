#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        l--; r--;
        
        vector<int> arr, brr;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            if (i <= r) arr.push_back(a);
            if (i >= l) brr.push_back(a);
        }

        int size = r-l+1; 
        
        sort(arr.begin(), arr.end());
        int sum1 = 0;
        for (int i = 0; i < size; i++){
            sum1 += arr[i];
        }
        
        sort(brr.begin(), brr.end());
        int sum2 = 0;
        for (int i = 0; i < size; i++){
            sum2 += brr[i];
        }
        
        cout << min(sum1, sum2) << endl;
    }   
}