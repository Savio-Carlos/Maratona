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
    string s, t;
    cin >> s;
    t = s;
    int cnt = 1;
    bool can = true;
    for (auto c : s){
        if (c == '#') cnt++;
    }
    for (auto &c : t){
        if (can && cnt && c == '.'){
            c = 'o';
            can = false;
            cnt--;
        }
        if (c == '#') can = true;
    }
    cout << t << endl;
}
