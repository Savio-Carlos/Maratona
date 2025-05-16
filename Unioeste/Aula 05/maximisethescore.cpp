#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> arr;
vector<int> visited;

int main () {
    int t, n;
    ll ans = 0;
    cin >> t;
    
    while (t--){
        cin >> n;
        arr.resize(n*2);
        ans = 0;
        for (int i = 0; i < n*2; i++){
            cin >> arr[i];
        }
    
        for (int i = 0; i < n; i++){
            ll n1 = *max_element(arr.begin(),arr.end());
            arr[distance(arr.begin(), max_element(arr.begin(), arr.end()))] = 0;

            ll n2 = *max_element(arr.begin(),arr.end());
            arr[distance(arr.begin(), max_element(arr.begin(), arr.end()))] = 0;

            ans+=min(n1,n2);
        }

    cout << ans << endl;

    }
}