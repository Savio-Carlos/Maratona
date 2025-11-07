#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    while(q--){
        int a, b; cin >> a >> b;
        auto l = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
        auto r = upper_bound(arr.begin(), arr.end(), b);
        if(r == arr.begin()){
            cout << 0 << endl;
        }else{
            int v = *prev(r);
            if(v <= b){
                int R = r-arr.begin()-1;
                cout << R-l+1 << endl;
            }else{
                int R = r-arr.begin();
                if(R == l && *(r) < b){
                    cout << 0 << endl;
                }
            }
            
        }
    }
}