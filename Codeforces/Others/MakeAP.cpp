#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5;

signed main() {
    winton;
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        if((!((2*b-c)%a) && (2*b-c) > 0)) cout << "YES" << endl;
        else if(!((2*b-a)%c) && (2*b-a) > 0) cout << "YES" << endl;
        else if((a+c)%(2*b)==0) cout << "YES" << endl;
	    else cout << "NO" << endl;
    }
}