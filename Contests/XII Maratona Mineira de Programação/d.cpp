#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

signed main(){
    fastio;
    int k;
    cin >> k;
    vector<int> v(25);
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            for(int k = 1; k <= 6; k++){
                v[i+j+k]++;
            }
        }
    }

    cout << fixed << setprecision(20) << (double)v[k] / (6*6*6) << endl;

}