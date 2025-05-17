#include <bits/stdc++.h>
using namespace std;
vector<long long> arr;
vector<long long> v;

int main() {
    long long n, q, a, b; 
    cin >> n >> q;

    arr.resize(n);
    v.resize(n + 1, 0); 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v[i + 1] = v[i] + arr[i]; 
    }

    while (q--) {
        cin >> a >> b;
        a--; b--; 
        long long sum = v[b + 1] - v[a];

        cout << sum << endl;
    }

    return 0;
}