#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    bool ans = true;
    for (int i = 0; i < n;i++){
        if(s[i] == t[i] && s[i] == 'o') ans = false;
    }
    if (ans) cout << "No" << endl;
    else cout << "Yes" << endl;
}