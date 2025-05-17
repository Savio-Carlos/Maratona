#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;

signed main(){
    winton;
    string s;
    cin >> s;
    cout << s << endl;
    while (s.size() != 1){
        int a0 = s[s.size()-1] - '0';
        s.erase(s.end()-1);
        //cout << s << endl;
        //cout << a0 << endl;
        int a1 = stol(s);
        //cout << a1 << endl;
        int res = a1 * 3 + a0;
        s = to_string(res);
        cout << s << endl;
    } 
}