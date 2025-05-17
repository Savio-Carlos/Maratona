#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 12;

vector<string> mp = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol",  "sol#",  "la",  "la#",  "si"};

signed main() {
    winton;
    
    vector<set<int>> escalas(12);
    vector<int> intervalo = {0,2,4,5,7,9,11};
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < intervalo.size(); j++){
            escalas[i].insert((intervalo[j]+i) % MOD);
        }
    }

    int n; cin >> n;
    set<int> notes;
    for (int i = 0; i < n; i++){
        int a; 
        cin >> a;
        a--;
        a%=MOD;
        notes.insert(a);
    }
    string ans = "desafinado";
    for (int i = 0; i < 12; i++){
        int pos = 1;
        for (auto u : notes){
            if (escalas[i].find(u) == escalas[i].end()) pos = 0;
        }
        if (pos){
            ans = mp[i];
            break;
        }
    }
    cout << ans << endl;
}