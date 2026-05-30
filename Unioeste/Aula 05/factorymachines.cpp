#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(){

    cin.tie(0)->sync_with_stdio(0);

    vector<int> maquinas;

    int n, t; cin >> n >> t;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        maquinas.push_back(x);
    }

    int min = 0;
    int max = 2*1e18;
    int mid = 0;

    while (min<max){
        mid = (min+max)/2;
        int sum = 0;
        for (auto i : maquinas){
            sum += mid/i;
            if (sum >= t){
                break;
            }
        }

        if (sum >= t){
            max = mid;
        }
        if (sum < t){
            min = mid+1;
        }
    }

    cout << max;

    return 0;
}