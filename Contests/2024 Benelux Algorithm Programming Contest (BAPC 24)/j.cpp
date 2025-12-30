#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n; cin >> n;
    int prevx = 0, prevy = 0;
    int pos = 1;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(prevx > a || prevy > b){
            pos = 0;
        }
        prevx= a;
        prevy=b;
    }
    if(pos) cout << "yes\n";
    else cout << "no\n";
}