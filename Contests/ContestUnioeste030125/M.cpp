#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAX = 10e9+7;

signed main() {_
    int n;
    cin >> n;
    vector<int> w(100);
    vector<bool> e(100,true);
    for (int i = 0; i < 100; i++){
        w[i] = i+1;
    }
    
    for(int i = 0; i < n; i++){
        string s;cin >> s;
        int a; cin >> a;
        if (s == "SUBTRACT"){
            for (int j = 0; j < 100; j++){
                w[j] -= a;
                if (w[j] < 0) e[j] = false;
            }
        }
        else if (s == "DIVIDE"){
            for (int j = 0; j < 100; j++){
                if (w[j]%a != 0) e[j] = false;
                w[j] /= a;
            }
        }
        else if (s == "ADD"){
            for (int j = 0; j < 100; j++){
                w[j] += a;
            }
        }
        else if (s == "MULTIPLY"){
            for (int j = 0; j < 100; j++){
                w[j] *= a;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 100; i++){
        if (!e[i]) ans++;
    }
    cout << ans << endl;
}