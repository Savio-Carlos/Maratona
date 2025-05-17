#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 1e7;

int main (){
    ll n,c;

    cin>>n>>c;

    map<string,ll> forca;

    while(n--){
        string s;
        cin >> s;
        ll pos;
        for(ll i = 0; i<c; i++){
            if(s[i]=='*'){
             pos = i;
            }
        }
        for(ll i = 0; i<26;i++){
            s[pos]='a'+i;
            forca[s]++;
        }
    }
    ll ans=0;
    string res;
    for(auto u:forca){
        if (u.second>ans){
            res = u.first;
            ans = u.second;
        }
    }

    cout<<res<<" "<<ans<<endl;
}