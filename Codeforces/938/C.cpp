#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

signed main() {_
    int t; cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        deque<int> ships(n);
        for (auto &i : ships) cin >> i;

        int sum = 0, i = 0, l = 0, r = n-1;
        int possible_atacks = k;

        while (ships.size() > 1 && possible_atacks > 0){
            int m = min(ships.front(), ships.back());
            if (possible_atacks >= m*2){
                ships.back() -= m;
                ships.front() -= m;
                possible_atacks -= m*2;
            }
            else {
                ships.back() -= possible_atacks/2;
                ships.front() -= possible_atacks/2 + possible_atacks%2;
                possible_atacks = 0;
            }
            if (ships.front() == 0) ships.pop_front();
            if (ships.back() == 0) ships.pop_back();
        }
        
        int ans = n - ships.size();
        if (ships.size() && ships.front() <= possible_atacks) ans++;
        cout << ans << endl;
    }
}
