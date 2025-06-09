#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 2e5;

int main(){
    minecraft;
    ll erro;
    string str;

    cin>>erro>>str;

    // cout<<str.size()<<endl;

    string tamo = "tamocompetindo";

    bool flag = false;

    if(str.size()<14){
        cout<<"NAO"<<endl;
        return 0;
    }

    for(ll i=0; i<str.size() - 13;i++){
        ll c = 0;
        for(ll k = i, j = 0; k<i+14; j++,k++){
            if(str[k]!=tamo[j]) c++;
        }
        // cout<<c<<endl;
        if(c<=erro){
            flag=true;
        }
    }

    if(flag){
        cout<<"SIM"<<endl;
    }
    else cout<<"NAO"<<endl;
}