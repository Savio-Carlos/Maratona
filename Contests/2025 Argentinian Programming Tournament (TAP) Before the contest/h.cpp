#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    sort(arr.begin(), arr.end());
    if(n == 1){
        if( arr[0] == 1) cout << "*\n";
        else cout << arr[0] << " " << 1 << endl;
    }
    else if(n == 2){
        //1 e 3 ou 1 e 9
        if(arr[0] == 1) {
            int x = sqrt(arr[1])*sqrt(arr[1]);
            if(x == arr[1]) cout << arr[1] << " " << sqrt(arr[1]) << endl;
            else cout << arr[1]*arr[1] << " " << arr[1]*arr[1];
        }
        else cout << arr[1] << " " << 1 << endl;
    }
    //1 3 9
    else if(n == 3){
        if(arr[0] == 1){
            if(arr[2]%arr[1] == 0){
                if(arr[2] == arr[1]*arr[1]) cout << arr[2]*arr[1] << " " << arr[2]*arr[1] << endl;
                else cout << arr[2] << " " << arr[2]/arr[1] << endl;
            }else cout << arr[2]*arr[1] << " " << arr[2]*arr[1] << endl;
        }else cout << arr[n-1] << " " << 1 << endl;
    }else{
        if(arr[0] != 1){
            cout << arr[n-1] << " " << 1 << endl;
        }else{
            int x = arr[n-1];
            if(arr[1]*arr[n-2] == x){
                cout << x << " ";
                for(int i = 0; i < n; i++){
                    if(mp[x/arr[i]] == 0){
                        cout << x/arr[i] << endl;
                        break;
                    }
                }
            }else cout << arr[1]*arr[n-1] << " " << arr[1]*arr[n-1] << endl;
        } 
    }
}

signed main(){
    fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}