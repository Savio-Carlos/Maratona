#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t;
    cin >> t;
    int score[10][10];
    int b = 10;
    int s = 1;
    for (int a = 0; a < 5; a++, b--, s++){
        for (int i = a; i < b; i++){
            for (int j = a; j < b; j++){
                score[i][j] = s;
            }
        }
    }

    while(t--){
        int ans = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                char c; cin >> c;
                if (c == 'X') ans += score[i][j];
            }
        }
        cout << ans << endl;
    }

}