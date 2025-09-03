#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_studio(0); cin.tie(0)
#define endl '\n'

const int MAXN = 1e5+7;
int n, c, t;
int arr[MAXN];

/*
dividir o array na menor soma possivel
faco uma busca binaria na menor soma possivel q eu consigo fazer com so C caras
ai eu rodo o algoritmo dnv pra soma minima e calculo quanto tempo vai ser 
necessario pra calcular isso pra K
passou da qtd de caras minimos pra essa soma ent return false
se a qtd de caras for menor q o c, ent return true pq consigo fazer
*/

int check(int mid){
    //soma e qtd de grupos
    int sum = 0, qtd = 1;
    for(int i = 0; i < n; i++){
        //se a soma for maior q k
        if(sum + arr[i] > mid){
            //cout << sum << " " << qtd << endl;
            qtd++;
            sum = 0;
        }
        sum += arr[i];
    }
    //cout << qtd << " " << mid << endl;
    return qtd <= c;
}

signed main(){
    cin >> n >> c >> t;
    int l = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        l = max(l, arr[i]);
    }
    
    int r = 2e18;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    if(!(l%t)) cout << l/t << endl;
    else cout << l/t+1 << endl;
}
