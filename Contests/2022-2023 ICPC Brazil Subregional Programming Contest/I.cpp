#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 1e7;

int main (){

    bool flag = false;

    for(ll i = 0; i<8; i++){
        ll n;
        cin >> n;
        if(n==9){
            flag = true;
        }
    }
    if(flag){
        cout<<"F"<<endl;
    }
    else cout<<"S"<<endl;
}