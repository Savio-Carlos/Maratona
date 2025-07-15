#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr)
ll const inf =1e5;

int main() {
    ll n;
    cin>>n;
    vector<ll>arr;
    arr.push_back(1);
    arr.push_back(1);
    for (ll i = 2; i <= n; i++){
        arr.push_back(arr[i-1]+arr[i-2]);
    }
    cout<<arr[n]<<endl;

return 0;
}