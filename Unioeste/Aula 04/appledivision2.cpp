#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define int long long

const int MAXN = 20;
int pesos[MAXN];

int mindiff(int soma1, int soma2, int n) {
   if (n == 0) {
        //cout << abs(soma1 - soma2) << endl;
        return abs(soma1 - soma2);
   }

    int grupo1 = mindiff(soma1 + pesos[n-1], soma2, n-1);
    int grupo2 = mindiff(soma1, soma2 + pesos[n-1], n-1);

    return min(grupo1, grupo2);
}

signed main() {
    int n, soma1=0, soma2=0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> pesos[i];
    }

    int min = mindiff(soma1, soma2, n);
    cout << min << endl;
    return 0;
}