#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;

    vector<ll> degR(N+1, 0), degC(N+1, 0);
    for(ll i = 0; i < M; i++){
        ll r, c;
        cin >> r >> c;
        degR[r]++;
        degC[c]++;
    }

    ll r0 = 0, U_r = 0;
    for(ll i = 1; i <= N; i++){
        if(degR[i] > 0){
            r0++;
            if(degR[i] == 1) U_r++;
        }
    }

    ll c0 = 0, U_c = 0;
    for(ll j = 1; j <= N; j++){
        if(degC[j] > 0){
            c0++;
            if(degC[j] == 1) U_c++;
        }
    }

    // quantos podemos realmente adicionar sem perder cobertura
    ll addR = min(K, M - U_r);
    ll addC = min(K, M - U_c);

    ll r = min(N, r0 + addR);
    ll c = min(N, c0 + addC);

    // células cobertas = r*N + c*N - r*c
    ll covered = r * N + c * N - r * c;
    cout << covered << "\n";

    return 0;
}
