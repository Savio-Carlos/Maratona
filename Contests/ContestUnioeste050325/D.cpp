#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXL = 1e9+7;

signed main() {_
    int n, q;
    cin >> n >> q;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < q; i++){
        int q; cin >> q;
        if(q==1){
            int k; cin >> k;
            if (!binary_search(v.begin(), v.end(), k)){
                if(k > v.back()){
                    v.push_back(k);
                } else {
                    *upper_bound(v.begin(), v.end(), k) = k;
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) << endl;
        }
    }
}