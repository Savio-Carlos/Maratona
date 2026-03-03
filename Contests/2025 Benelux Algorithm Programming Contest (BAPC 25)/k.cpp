#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 

signed main(){
    fastio;
    int h, m;
    cin >> h >> m;
    int goal = (h * 2) % 60;
    // cout << goal << endl;
    if (goal * 6 == m) cout << "yes\n";
    else cout << "no\n";
}