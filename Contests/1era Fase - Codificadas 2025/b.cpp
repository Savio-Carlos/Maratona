#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

signed main(){
    winton;
    string s;
    cin >> s;
    map<char,int> mp;
    for (auto c : s) mp[c]++;
    if (mp['T'] == mp['C'] && mp['S'] == mp['C']) cout << "YES" << endl;
    else cout << "NO" << endl;
}