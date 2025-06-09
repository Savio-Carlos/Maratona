#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    a[0] = 1;
    a[n-1] = 2;
    int menor = 3;
    int maior = n;
    for (int i = 1; i < n-1; i++){
        if (i&1){
            a[i] = menor++;
        }
        else a[i] = maior--;
    }
    for (auto u : a) cout << u << " ";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}