#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);

int main() {_
    ll t;
    cin>>t;
    while (t--) {
        ll n,resposta;
        cin>>n;
        vector<char>olhos1;
        vector<char>olhos2;
        vector<char>boca;
        ll flag = 0;
        for(ll i = 0; i < n; i++) {
            char c;
            cin>>c;
            if(c=='-') {
                if(flag){
                    olhos2.push_back(c);
                    flag = 0;
                }
                else {
                    olhos1.push_back(c);
                    flag = 1;
                }
            }
            else boca.push_back(c);
        }
        resposta = olhos1.size()*olhos2.size()*boca.size();
        cout<<resposta<<endl;
    }
    return 0;
}


