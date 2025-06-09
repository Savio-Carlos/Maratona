#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 2e5;

int main(){
    minecraft;
    ld d,t,k,v;

    ld lamb;

    cin>>d>>t>>k>>v>>lamb;

    ld tempo = (d-k)/v;
    v*=lamb;

    if(tempo>t){
        cout<<fixed<<setprecision(10)<<t*v+k<<endl;
    }
    else {
        ll c=0;
        while(d/v+tempo<=t){
            //cout << tempo << endl;
            //cout << v << endl;
            tempo+=d/v;
            v*=lamb;
            c++;
        }
        cout << tempo << endl;
        if (c%2){
            cout<<fixed<<setprecision(10)<<(t-tempo)*v<<endl;
        }
        else cout<<fixed<<setprecision(10)<<d-(t-tempo)*v<<endl;
    }
}