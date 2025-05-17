#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define M_PI 3.14159265358979323846
const int MAX = 2e5+7;

signed main() {
    winton;
    int ab, c;
    cin >> ab >> c;
    ld ang1 = ab * M_PI / 180;//converte pra radianos
    ld ang2 = c * M_PI / 180;
    ld altura1 = sin(ang1);//usa o seno pra calcular a altura
    ld altura2 = sin(ang2);
    
    //cout << "angulos"<<endl<<ang1 << " ang2: " << ang2 << endl;
    //cout << "alturas"<<endl<<altura1 << " altura2: " << altura2 << endl;
    
    if (fabs(altura2 - altura1) == 0) cout << "O Claudio ta do outro lado da roda!";
    else if (altura2 > altura1) cout << "Olha o Claudio ali em cima!" << endl;
    else cout << "O Claudio ta ali embaixo!" << endl;
}