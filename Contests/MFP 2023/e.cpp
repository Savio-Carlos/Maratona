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

/*
 g = (f * d^2)/(m1*m2)
*/

signed main(){
    winton;
    int p;
    cin >> p;
    int cnt = 0;
    for (int i = 0; i < 7; i++){
        int a;
        cin>> a;
        if (a)cnt++;
    }
    if (p){
        if (cnt&1) cout << "N?" << endl;
        else cout << "S" << endl;
    }
    else {
        if (cnt&1) cout << "S" << endl;
        else cout << "N?" << endl;
    }
}