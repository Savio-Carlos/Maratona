#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    winton;
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<tuple<int,int,int>> pairs;
    for (auto &u : a) cin >> u;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            pairs.push_back({(a[i] + a[j]), i, j});
       
        }
    }
    sort(all(pairs));
    int l = 0, r = pairs.size()-1;
    while (l < r){
        auto [v, i1, j1] = pairs[r];
        auto [u, i2, j2] = pairs[l];
        int sum = u+v;

        if (i1 == i2 || j1 == j2 || i1 == j2 || j1 == i2){
            if (u == get<0>(pairs[l+1])) l++;
            else r--;
            continue;
        }

        if (sum == x){
            cout << i1+1 << " " << i2+1 << " " << j1+1 << " " << j2+1 << endl;
            return 0;
        }

        if (sum > x) r--;
        else l++;
    }   
    cout << "IMPOSSIBLE" << endl;
}
