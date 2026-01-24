#include <vector>
#include <iostream>
using namespace std;

#define winton ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int xsum = 0;
    bool all1 = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xsum ^= a[i];
        if (a[i] > 1) all1 = false;
    }
    if ((!all1 && xsum == 0) || (all1 && n&1)) cout << "Brother" << endl;
    else cout << "John" << endl; 
}

signed main(){
    // winton;
    int t;
    cin >> t;
    while(t--)solve();
}