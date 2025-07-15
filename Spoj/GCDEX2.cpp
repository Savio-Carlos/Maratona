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

/*
precomputePHI //aqui eu conto quantos combinacoes de 1 - N tem gdc = 1

entao preciso contar quantas combinacoes tem o gcd != 1
por ex para o 10 seriam
2 4 = 2
2 6 = 2
2 8 = 2
2 10 = 2
4 6 = 2
4 10 = 2
6 8 = 2
6 10 = 2
8 10 = 2

3 6 = 3
3 9 = 3
6 9 = 3

4 8 = 4

5 10 = 5

Therefore, the number of integers a in the set {1, 2, ..., n} with gcd(a, n) = d is equal to φ(n/d). 
*/

int phi[MAX], arr[MAX], pfx1[MAX];
map<pair<int,int>,int> memo;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void precomputePHI() {
	for (int i = 1; i < MAX; i++) { phi[i] = i; }
	for (int i = 2; i < MAX; i++) {
		if (phi[i] == i) {
			for (int j = i; j < MAX; j += i) { phi[j] -= phi[j] / i; }
		}
	}
	for (int i = 1; i < MAX; i++){
		pfx1[i] = (phi[i] + pfx1[i-1]);
	}
}

int func(int n, int d){
	if (memo.find({n,d}) != memo.end()) return memo[{n,d}];
	if (d != 1) return func(n/d,1);
	return memo[{n,d}] = pfx1[n]-1;
}

signed main(){
	winton;
	int n;
	precomputePHI();
	//for (int i = 1; i <= n; i++)cout << i << ": " << pfx1[i] << endl;
	while(cin >> n){
		if (n == 0) break;
		int divi = 0;
		for (int i = 1; i <= n; i++){
			divi+= func(n,i) * i;
			// debug(i);
			// debug(divi);
		}
		cout << divi << endl;
	}
}