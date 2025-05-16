#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> arr;

int main() {
    int n, q;
    ll m;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> q;
    sort(arr.begin(), arr.end());
    while(q--){
        cin >> m;
        cout << distance(arr.begin(),upper_bound(arr.begin(),arr.end(),m)) << endl;
    }

}