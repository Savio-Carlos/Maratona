#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;

int gcdd(int a, int b) {
    return b == 0 ? a : gcdd(b, a % b);
}

int mmmc(int a, int b) {
    return a / gcdd(a, b) * b;
}

signed main() {
    winton;
    int t;
    cin >> t;
    while(t--){
        int h1, m1, h2, m2;
        char trash;
        cin >> h1 >> trash >> m1 >> h2 >> trash >> m2;
        //cout << h1 << " " << m1 << " " << h2 << " " << m2 << endl;
        int timer1 = h1*3600 * 1000 + m1 * 60 * 1000;//converte de horas pra milesimos e minutos pra milesimos
        int timer2 = h2*3600 * 1000 +m2 * 60 * 1000;
        int hz1, hz2;
        cin >> hz1 >> hz2;
        hz1 *= 1000;
        int mmc = mmmc(hz1, hz2);
        int dur = timer2 - timer1;
        cout << dur << " " << mmc << endl;
        int ans = (dur + mmc - 1)/mmc;
        cout << ans << endl;
    }
}