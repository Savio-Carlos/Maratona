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
    int n;cin >> n;
    map <string,int> names;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        string s = "";
        for (int j = 0; j < a; j++){
            string name; cin>>name;
            //cout << name <<  " ";
            s += name[0]; 
        }
        names[s]++;
    }
    for (auto u : names){
        if (u.second == 1)ans++;
    }
    cout <<  ans << endl;
}
