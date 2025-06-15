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
    int n, k;
    cin >> n >> k;
    int aux = n-k;
    for (int i = 0; i < aux; i++)cout << "0";
    for (int i = 0; i < k; i++)cout << "1";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}