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

/*
 g = (f * d^2)/(m1*m2)
*/

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> visit;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        visit.push_back({--a,--b});
    }
    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (i&1) cout << "1";
        else cout << "0";
    }
    cout << endl;
}