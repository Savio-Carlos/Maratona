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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0, open = 0, close = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '(') open++;
        else if (s[i] == ')') close++;

        if (close > open && s[i] == ')'){
            open = close = 0;
            ans = i+1;
        } 
    }
    cout << ans << endl;
}