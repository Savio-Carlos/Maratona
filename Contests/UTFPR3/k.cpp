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
const int MAX = 1e5+7;
const int INF = INT_MAX;

bool check(string s){
    int len = s.size();
    for (int i = 0; i < len; i++){
        if (s[i] != s[len-i-1]) return false;
    }
    return true;
}

signed main(){
    winton;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if (check(s)) cout << "SIM" << endl;
        else cout << "NAO" << endl;
    }
}