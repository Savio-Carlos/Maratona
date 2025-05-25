#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ld cntisolado = 0, cntnormal = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '*') cntisolado++;
        if (t[i] == '*') cntnormal++;
    }
    ld ans = 1 - (cntnormal/cntisolado);
    cout << fixed << setprecision(2) <<  ans << endl;
}