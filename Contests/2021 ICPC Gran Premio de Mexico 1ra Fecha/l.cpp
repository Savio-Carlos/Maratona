#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define winton ios_base::sync_with_stdio(0),cin.tie(0)

void func(int k){
    if (k == 1){
        cout << "2";
        return;
    }
    if (k&1){
        k--;
        cout << "(2*";
        func(k);
        cout << ")";
        return;
    }
    else {
        k/=2;
        cout << "(";
        func(k); 
        cout << ")^2";
    }
}

void solve(){
    int k;
    cin >> k;
    func(k);
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}   
