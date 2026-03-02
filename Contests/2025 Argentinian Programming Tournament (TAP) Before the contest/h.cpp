#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(a.begin(), a.end());
    if(n == 1){
        if(a[0] == 1) cout << "*\n";
        else cout << a[0] << " " << 1 << endl;
        return ;
    }

    int sq = sqrtl(a.back());
    bool has_sq = false;//se eu n tenho a sq do numero como divisor e e uma raiz inteira, entao e ela q ta faltando
    for (auto u : a) if (u == sq) has_sq = true;
    if (!has_sq && sq*sq == a.back()){
        cout << a.back() << " " << sq << endl;
        return ;
    }
    //assumindo que a.back e o X, procuro qual divisor ta faltando
    for (int i = 0; i < n; i++){
        if (a.back() % a[i]) break; //se a.back n divide um dos numeros do vetor, a.back nao e o X
        if (!mp.count(a.back() / a[i])){
            cout << a.back() << " " << a.back() / a[i] << endl;
            return;
        }
    }
    cout << a[1] * a.back() << " " << a[1] * a.back() << endl;


}

signed main(){
    fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}