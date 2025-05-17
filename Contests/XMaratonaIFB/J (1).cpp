#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;

signed main() {
    winton;
    int ab, c;
    cin >> ab >> c;
    ld ang1 = fmod((ab % 360 + 360), 360) * M_PI / 180;
    ld ang2 = fmod((c  % 360 + 360), 360) * M_PI / 180;
    ld altura1 = sin(ang1);
    ld altura2 = sin(ang2);
    ld diff = fabs(ang1 - ang2);
    if (fabs(fmod(diff, 2*M_PI) - M_PI) < 1e-9) cout << "O Claudio ta do outro lado da roda!" << endl;
    else if (fabs(altura2 - altura1) < 1e-9) cout << "O Claudio ta do outro lado da roda!";
    else if (altura2 > altura1) cout << "Olha o Claudio ali em cima!" << endl;
    else cout << "O Claudio ta ali embaixo!" << endl;
}