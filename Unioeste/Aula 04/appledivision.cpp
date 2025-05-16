#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define ll long long
int n;
vector<ll> pesos;

ll mindiff(ll soma1, ll soma2, int n) {
     //cout << "soma1 "<< soma1 << " soma2 " << soma2 << " n " << n << " abs " << abs(soma1-soma2) << endl;
   if (n == 0) return abs(soma1 - soma2);
   
    ll grupo1 = mindiff(soma1 + pesos[n-1], soma2, n-1);
    ll grupo2 = mindiff(soma1, soma2 + pesos[n-1], n-1);

    return min(grupo1, grupo2);
}

int main() {
    ll soma1 = 0, soma2 = 0;
    cin >> n;
    pesos.resize(n);

    for (int i = 0; i < n; i++){
        cin >> pesos[i];
    }

    ll min = mindiff(soma1, soma2, n);
    cout << min << endl;

    return 0;
}