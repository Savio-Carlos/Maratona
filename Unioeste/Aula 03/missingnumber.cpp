#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n;
    int arr[n+1] = {};

    for (int i = 1; i < n; i++){
        cin >> m;
        arr[m] = 1;
    }
    
       for (int i = 1; i <= n; i++){
        if (arr[i]==0) cout << i;
    }
}