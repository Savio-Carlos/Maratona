
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

signed main() {_
    int t; cin >> t;
    while (t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        int goal = 0;
        for (int i = 0; i < n; i++){
            if ((i|x) > x){ 
                arr[i] = arr[i-1];
            }
            else arr[i] = i;
            goal |= i;
        }
        if (goal != x) arr[n-1] = x;
        for (auto &i : arr) cout << i << " ";
        cout << endl;
    }
}
