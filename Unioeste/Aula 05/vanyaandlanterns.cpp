#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> street;

int main() {
    int n;
    ll l, gap_inicial, gap_final;
    double aux = 0, gap_maior = 0, ans;
    cin >> n >> l;
    street.resize(n);
    for (int i = 0; i < n; i++){
        cin >> street[i];
    }
    sort(street.begin(), street.end());
    gap_inicial = (street[0] - 0);
    gap_final = (l-street[n-1]);

    //cout << gap_inicial << " " << gap_final << endl; 
    for (int i = 0; i < n-1; i++){
        aux = abs(street[i] - street[i+1]);
        aux = aux/2;
        if (aux > gap_maior) gap_maior = aux;
    }
    //cout << gap_maior << endl;
    //printf ("%lf\n",gap_maior);
    ans = max(gap_final, gap_inicial);
    ans = max(ans, gap_maior);
    printf ("%.8lf\n",ans);
}