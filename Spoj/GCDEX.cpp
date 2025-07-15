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
const int MAX = 1e6+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

int phi[MAX], ans[MAX];

void precomputePHI() {
	for (int i = 1; i < MAX; i++) { phi[i] = i; }
	for (int i = 2; i < MAX; i++) {
		if (phi[i] == i) {
			for (int j = i; j < MAX; j += i) { phi[j] -= phi[j] / i; }
		}
	}
}

signed main(){
	winton;
	int n;
	precomputePHI();
	for (int i = 1; i < MAX; i++){
		for(int m = 2*i; m < MAX; m += i){
            ans[m] += i * phi[m/i];
        }
		if (i > 1)ans[i] += ans[i-1];
	}
	while(cin >> n && n){
		cout << ans[n] << endl;	
	}
}