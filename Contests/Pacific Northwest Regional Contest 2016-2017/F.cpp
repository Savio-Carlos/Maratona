#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e3+7;
const int MOD = 1e9+7;

signed main(){
    winton;
    char a, b, c, trash;
    cin >> a >> trash >> b >> trash >> c;
    if (a-'0'+b-'0' == c-'0') cout <<"YES"<<endl;
    else cout << "NO" << endl;   
}