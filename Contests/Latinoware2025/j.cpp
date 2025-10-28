#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

signed main(){
    int m,t,l;
    cin>>m>>t>>l;
    if(t / m < l) {
        cout << 'N' << endl;
        return 0;
    }
    cout << 'S' << endl;
}