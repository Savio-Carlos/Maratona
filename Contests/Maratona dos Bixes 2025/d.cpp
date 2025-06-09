#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 2e5;

int main(){
    minecraft;

    vector<pair<ll,ll>> pontos (4);

    for(ll i = 0; i < 4; i++){
        cin>>pontos[i].first>>pontos[i].second;
    }

    vector<ll> dis;

    for(ll i = 0; i < 4; i++){
        ll x = pontos[i].first-pontos[(i+1)%4].first;
        ll y = pontos[i].second-pontos[(i+1)%4].second;
        ll dist = (x*x)+(y*y);
        dis.push_back(dist);
    }

    bool flag = true;

    for(ll i = 0; i<dis.size()-1; i++){
        if(dis[i]!=dis[i+1]){
            flag = false;
        }
    }

    ll x = pontos[0].first-pontos[2].first;
    ll y = pontos[0].second-pontos[2].second;
    ll dist = (x*x)+(y*y);

    ll x2 = pontos[1].first-pontos[3].first;
    ll y2 = pontos[1].second-pontos[3].second;
    ll dist2 = (x2*x2)+(y2*y2);

    if(dist!=dist2){
        flag=false;
    }

    if(flag){
        cout<<"SIM"<<endl;
    }
    else cout<<"NAO"<<endl;
}