#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAX = 62;

// int fastexpo(int a, int b){
//     int res = 1;
//     while(b > 0){
//         if(b&1) res = (res*a);
//         a = (a*a);
//         b /= 2;
//     }
//     return res;
// }

/// @brief 
/// @return 
signed main(){
     fastio;
    //  cout << LLONG_MAX << endl;
    int d, y;
    cin >> d >> y;
    vector<int> deslocamento;
    deslocamento.push_back(1);
    for (int i = 1; i < MAX; i++){
        deslocamento.push_back((1LL << (i)) + (1LL << (i-1)));
    }
    int n = deslocamento.size();
    // cout << deslocamento[n-1] << endl;
    vector<int> pfx(n);
    for (int i = 0; i < n; i++){
        pfx[i] = deslocamento[i];
        if (i) pfx[i] += pfx[i-1];
    }
    // cout << pfx[n-1] << endl;`
    // cout << "deslocamento" << endl;
    // for (auto u : deslocamento) cout << u << " ";
    // cout << endl;

    // cout << "pfx" << endl;
    // for (auto u : pfx) cout << u << " ";
    // cout << endl;

    int lmax = LLONG_MAX, rmax = LLONG_MIN;
    int dd = d;
    int pos = y;
    int st;
    bool dir = 0;
    for (int i = 0; i < n; i++){
        dir = !dir;
        if (pfx[i] >= dd){
            st = i;
            break;
        }
    }
    // cout << "st: " << st << endl;

    for (int i = st; i >= 0; i--){
        int disl;
        if (pfx[i] != dd) disl = dd - pfx[i-1];
        else disl = deslocamento[i];
        // cout << "disl: " << disl << endl;
        if (dir){
            pos -= disl;
        }
        else{
            pos += disl;
        }
        dd -= disl;
        // cout << "i: " << i << " pos: " << pos << endl;
        dir = !dir;
        lmax = min(lmax, pos);
        rmax = max(rmax, pos);
        // cout << lmax << " " << rmax << endl;y
    }
    if (y < lmax || y > rmax){
        cout << "Sim\n";
        cout << pos << endl;
    }
    else cout << "Nao\n";

}