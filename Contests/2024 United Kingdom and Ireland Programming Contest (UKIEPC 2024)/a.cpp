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
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a1(26), a2(26);
    for (char &c : s1){
        a1[c-'a']++;
    }
    for (char &c : s2){
        a2[c-'a']++;
    }
    for (int i = 0; i < 26; i++){
        int mx = max(a1[i], a2[i]);
        for (int j = 0; j < mx; j++){
            char cur = i + 'a';
            cout << cur;
        }
    }
}