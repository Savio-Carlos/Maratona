#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 5e4+7;

signed main(){
    winton;
    string s;
    cin >> s;
    //cout << s;
    if (s[3] == 'S' && s[4] == 'P') cout << "S" << endl;
    else if (s[3] == '?' && s[4] == 'P' || s[3] == 'S' && s[4] == '?') cout << "T" << endl;
    else cout << "N" << endl;
}