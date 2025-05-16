#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> dif;

int main() {
    int n, ans=0;
    ll m, a, b, soma;
    cin >> n >> m;

    dif.resize(n);
 
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        dif[i] = a-b;
        soma+=a;       
    }
    //cout << "somatotal " << soma << " m " << m << endl;
    int i=0;
    sort(dif.begin(), dif.end(), greater<ll>());
    while (soma>m){
        soma-=dif[i];
        i++;
        ans++;
        //cout << soma << endl;
        if (i > n) {
            ans = -1; 
            break;
        }
    } 

    cout << ans << endl;
    


}