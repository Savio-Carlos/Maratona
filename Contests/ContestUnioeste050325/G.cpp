#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXL = 1e9+7;

signed main() {_
    int n; cin >> n;
    vector<string> a;
    int intervalo = 2;
    a.push_back("Jane");
    int i = 1;
    while (i < n){
        for (int j = 0; j < intervalo; j++){
            a.push_back("John");
            i++;
        }
        for (int j = 0; j < intervalo; j++){
            a.push_back("Jane");
            i++;
        }
        intervalo++;
    }
    cout << a[n-1] << endl;
}