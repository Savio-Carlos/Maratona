#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_studio(0); cin.tie(0)
#define endl '\n'

signed main(){
    int n, k; cin >> n >> k;
    int tot = n*k;

    for(int i = 10; i <= 90; i+= 10){
        int val = tot*i;
        double val2 = (double)val/100.0;
        int val3 = ceil(val2);
        cout << val3 << " ";
    }
    cout << endl;
}