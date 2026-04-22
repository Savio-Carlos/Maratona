#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--){
        ll n, x, ans = 0, sum = 0, maior = 0;
        cin >> n >> x;
        vector<ll> car(n);
        for (int i = 0; i < n; i++){
            cin >> car[i];
            maior = max(maior,car[i]);
            sum += car[i];
        }
        ll media = (sum+x-1)/x;
        ans = max(media,maior);

        cout << ans << endl;
    }
}

/*
1
7 4
2 5 3 3 5 2 5
        for (int i = 0; i < n; i++){
            cout << car[i];
        }
        cout << endl;

*/