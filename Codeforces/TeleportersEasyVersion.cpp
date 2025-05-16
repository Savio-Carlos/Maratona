#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

signed main() {
    winton;
    int t;
    cin >> t;
    while (t--){
        int n, c;
        cin >> n >> c;
        vector<int> cost(n);
        for (int i = 0; i < n; i++){
            cin >> cost[i];
            cost[i] += i+1;
        } 
        sort(all(cost));
        int i = 0, ans = 0;
        while(c >= cost[i] && i < n){
            c-=cost[i];
            ans++;
            i++;
        }
        cout << ans << endl;
    }
}