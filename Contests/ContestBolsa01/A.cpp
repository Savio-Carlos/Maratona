#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXL = 1e9+7;

signed main(){_
    int n;
    cin >> n;
    vi cells(n);
    for (int i = 0; i < n; i++){
        cin >> cells[i];
    }
    
    sort(all(cells));
    int ans1 = LLONG_MAX;
    for (int i = 1; i < n; i++){
        ans1 = min((360 - cells[i]) + cells[i-1], ans1);
    }
    int ans2 = cells[n-1] - cells[0];
    if (n == 1)cout << "1" << endl;
    else cout << min(ans1,ans2) + 1 << endl;
}