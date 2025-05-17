#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAX = 10e9+7;

signed main() {_
    int n, k;
    cin >> n >> k;
    int menor = 1, maior = k;

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        string s; cin >> s;
        if (s == "SAFE") menor = max(a, menor);
        else if (s == "BROKEN") maior = min(a, maior);
    }
    
    cout << menor+1 << " " << maior-1 << endl;
}