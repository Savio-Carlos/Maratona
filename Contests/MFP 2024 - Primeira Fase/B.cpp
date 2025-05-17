#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MOD = 1e8;
const int MAXN = 1e2+7;
const int MAXM = 1e4+7;

signed main(){  
    winton;
    vector<pair<int,int>> coords(4);
    for (int i = 0; i < 4; i++){
       cin >> coords[i].first >> coords[i].second;
    }
    int h, l;
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (coords[i].first != coords[j].first) l = abs(coords[i].first - coords[j].first);
            else if (coords[i].second != coords[j].second) h = abs(coords[i].second - coords[j].second);
        }
    }
    cout << h*l << endl;
}
