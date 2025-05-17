#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        a[0] = 2;
        a[1] = 3;
        for (int i = 2; i < n; i++){
            a[i] = i*2+1;
        }
        for (auto u : a) cout << u << " ";
        cout << endl;
    }
}