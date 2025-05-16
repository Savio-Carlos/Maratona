#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXL = 1e9+7;

signed main(){_
	int t; cin>>t;
	while(t--){
		int n; cin >> n;
		vi arr(n);
		for(auto &i : arr) cin >> i;
		bool possible = false;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(gcd(arr[i],arr[j]) <= 2) possible = true;
			}
		}
		if(possible) cout << "YES" <<endl;
		else cout << "NO" << endl;
	}
}