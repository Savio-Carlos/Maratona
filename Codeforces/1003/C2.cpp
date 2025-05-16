#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;


signed main() {_
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (auto &i:arr) cin >> i;
        vector<int> brr(m);
        for (auto &i:brr) cin >> i;

        sort(brr.begin(), brr.end());
        bool possible = true;
        arr[0] = min(arr[0], brr[0]-arr[0]);
        for (int i = 1; i < n; i++){
            int l = 0, r = m-1;
            int nt = -1;

            while (l <= r){
                int mid = l+(r-l)/2;
                int a = brr[mid] - arr[i];
                if (a >= arr[i-1]){
                    r = mid - 1;
                    nt = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            if (m == 1) nt = 0;
            if (nt == -1 || nt >= m){
                if (arr[i] < arr[i-1]) {
                    possible = false;
                    break;
                }
            } else {
                int temp = min(arr[i],brr[nt]-arr[i]);
                int tmp = max(arr[i],brr[nt]-arr[i]);
                if (temp >= arr[i-1]) arr[i] = temp;
                else if (tmp >= arr[i-1]) arr[i] = tmp;
                else{
                    possible = false;
                    break;
                }
            }   
        }
        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
}