#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
const int MAXN = 2e6+7;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <class T> 
//     using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(){
    fastio;
    set<int> s;
    for(int i = 1; i < MAXN; i++){
        s.insert(i);
    }
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s.erase(arr[i]);
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int pos = arr[x-1];
        int nw = *s.lower_bound(pos);
        cout << nw << endl;
        s.erase(nw);
        arr[x-1] = nw;
        s.insert(pos);
    }
}