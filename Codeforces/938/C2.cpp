
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int t; cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> ships(n);
        for (auto &i : ships) cin >> i;
        int sum = 0;
        int possible_atacks = ceil(k/2);
        int de = 0;
        int i = 0;
        for (i = 0; i < n; i++){
            if (ships[i] <= possible_atacks){
                possible_atacks-=ships[i];
                de++;
            }
            else{
                ships[i] -= possible_atacks;
                break;
            } 
        }

        int spa = (k)/2;
        if (k%2 == 1) spa++;
        for (int j = n-1; j >= i; j--){
            if (ships[j] <= spa){
                spa-=ships[j];
                de++;
            }
            else break;
        }
        
        cout << de << endl;
    }
}
