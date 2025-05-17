#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main () {
    winton;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i <n; i++){
        cin >> a[i];
    }
    sort(rall(a));
    set<int>ans;

    for (int i = 0; i <n; i++){
        if (ans.find(a[i]*k) == ans.end()){
            ans.insert(a[i]);
        }
    }
    cout << ans.size() << endl;
}