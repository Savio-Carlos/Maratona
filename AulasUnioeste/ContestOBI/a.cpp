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
    int ans = 0;
    for (int i = 0; i < 6; i++){
        char a;
        cin >> a;
        if (a == 'V')ans++;
    }
    if (ans == 0) cout << "-1" << endl;
    else if (ans > 0 && ans < 3) cout << "3" << endl; 
    else if (ans > 2 && ans < 5) cout << "2" << endl; 
    else cout << "1" << endl; 
}
