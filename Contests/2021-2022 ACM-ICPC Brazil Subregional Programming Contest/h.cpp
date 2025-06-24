#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    bool pos = true;
    for (int i = 1; i <= n; i++){
        if (a[i].first != i){
            if (a[a[i].first].second != a[i].second) pos = false;
            else swap(a[i], a[a[i].first]);
        }
    }
    if (pos) cout << "Y" << endl;
    else cout << "N" << endl;
}