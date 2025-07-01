#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int INF = LLONG_MAX;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> dist(n), pref(n);
    for (int i = 1; i < n; i++){
        cin >> dist[i];
        pref[i] = dist[i];
        if (i) pref[i] += pref[i-1];
    }
    for (int i = 1; i < n; i++){
        for (int j = i; j < n; j++){
            cout << pref[j] - pref[i-1] << " ";
        }
        cout << endl;
    }
}