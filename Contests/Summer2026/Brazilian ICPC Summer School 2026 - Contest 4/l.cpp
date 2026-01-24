#include <bits/stdc++.h>
using namespace std;

#define winton ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    for(int i = 2; i < n; i++){
        int a = arr[i-2];
        int b = arr[i-1];
        int c = arr[i];
        if(a + b > c && b + c > a && a + c > b){
            cout << "possible\n";
            return;
        }
    }
    cout << "impossible\n";
}

signed main(){
    winton;
    solve();
}