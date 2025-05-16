#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int main(){
    int t;
    cin >> t;
    ll enes[t];
    ll kas[t];

    for (int i = 0; i < t; i++){
        cin >> enes[i];
    }
    for (int i = 0; i < t; i++){
        cin >> kas[i];
    }

    for (int i = 0; i < t; i++){
        ll C[enes[i]+1][enes[i]+1] = {};
        for (int n = 0; n < enes[i]+1; n++) { // loop over n from 0 to N-1 (inclusive)
            C[n][0] = 1;
            C[n][n] = 1;
            for (int k = 1; k < n; k++){// loop over k from 1 to n-1 (inclusive)
                C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
            } 
        }
            for (int j = 0; j < enes[i]; j++){
                for (int k = 0; k < enes[i]; k++){
                    cout << C[j][k] << " ";
            }
            cout << endl;   
        }
        cout << C[enes[i]][kas[i]] << endl;
    }
}