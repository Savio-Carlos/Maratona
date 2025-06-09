#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 2e5;

int main(){
    minecraft;

    ll n,k;

    cin>>n>>k;

    vector<pair<ll,ll>> aura (n);

    for(ll i = 0; i < n; i++){
        cin>>aura[i].first>>aura[i].second;
    }

    sort(aura.begin(),aura.end());

    ll i = 0;

    while(i<n && k>=aura[i].first){
        k+=aura[i].second;
        i++;
    }

    cout<<k<<endl;
}