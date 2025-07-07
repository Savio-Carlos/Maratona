#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int INF = 1e9+7;


signed main () {_
    int n;
    int ans = 0;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    arr[n] = INF;
    int d;
    cin >> d;
    for (int i = 0; i < n; i++){
        if (arr[i] + d > arr[i+1]){
            ans += abs(arr[i]-arr[i+1]);
        }
        else ans+=d;
       // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}