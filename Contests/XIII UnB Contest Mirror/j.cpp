#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int a, b; cin >> a >> b;
    int x = a*b;
    if(x&1) cout << "W\n";
    else cout << "P\n";
    
}