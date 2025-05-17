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
    ld a, b, c;
    cin >> a >> b >> c;
    char s; cin >> s;
    if (s == 'A'){
        int x = a + (b/2)*3 + (c/2)*5;
        cout << x << endl;
    }
    else if (s == 'B'){
        a += (c/2)*5;
        int x = b + (a/3)*2;
        cout << x << endl; 
    }
    else {
        a += (b/2)*3;
        int x = c + (a/5)*2;
        cout << x << endl; 
    }
}