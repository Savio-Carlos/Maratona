#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

signed main(){
    winton;
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        vector<int> candies(n+1);
        for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			candies[x]++;
		}
		sort(rall(candies));
		int ans = candies[0];
		int last = candies[0];
		for (int i = 1; i <= n; ++i) {
			if (last == 0) break;
			if (candies[i] >= last) {
				ans += last - 1;
				last --;
			} else {
				ans += candies[i];
				last = candies[i];
			}
		}
		cout << ans << endl;
    }
}