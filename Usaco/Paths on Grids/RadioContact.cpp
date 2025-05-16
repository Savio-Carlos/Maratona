#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e3+7;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int n, m, fx, fy, bx, by, dp[MAXN][MAXN];
string john, bessie;

int brute (int ij, int ib, int c){//onde o brute e testar todas as opcoes de movimentos
    if (ij == john.size() && ib == bessie.size()) return c;

    int cur = 0;

    if (ij < john.size()){
        int a = brute(ij+1, ib, c);
    }
    if (ib < bessie.size()){
        int b = brute(ij, ib+1, c);
    }
    return dp[ij][ib] + min(a,b);
}


signed main() {
    winton;
    //setIO("radio");
    cin >> n >> m >> fx >> fy >> bx >> by >> john >> bessie;
    brute(0,0);
    cout << dp[n][n] << endl;
}