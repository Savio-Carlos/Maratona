#include <bits/stdc++.h>
using namespace std;
#define ld long long long long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = LLONG_MAX;

signed main(){
    winton;
    int d, m;
    cin >> d >> m;
    ld seg = sqrt((ld)(d*d*2));//tamanho do segmento
    int quantos = m / seg;//quantos ele ja percorre
    ld restante = m - (quantos*seg);    //quanto falta ate o final desse seg
    ld n = sqrt((restante*restante)/2); //
    ld y = (quantos&1)? (ld)d-n : n;
    ld x = quantos*d + n;
    cout << fixed << setprecision(10) << x << " " << fixed << setprecision(10)<< y << endl;
}