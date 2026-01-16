#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n;
    cin >> n;
    for(int i = -999; i <= 999; i++){
        for(int j = -999; j <= 999; j++){
            if(i != 0  && j != 0 && i + j == n){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}