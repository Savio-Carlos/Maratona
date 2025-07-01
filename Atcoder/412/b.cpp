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
const int INF = LLONG_MAX;

signed main(){
    winton;
    string s, t;
    cin >> s >> t;
    map<char,int> freq;
    for (int i = 0; i < t.size(); i++){
        freq[t[i]]++;
    }
    bool ans = true;
    for (int i = 1; i < s.size(); i++){
        if (s[i] >= 65 && s[i] <= 90){
            if (!freq.count(s[i-1]))ans = false;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}