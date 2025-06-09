#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 2e5;

int main(){
    ll p,r,g,x;

    cin>>p>>r>>g>>x;

    if(g*x<=r){
        cout<<g*x*p<<endl;
    }
    else cout<<r*p<<endl;
}