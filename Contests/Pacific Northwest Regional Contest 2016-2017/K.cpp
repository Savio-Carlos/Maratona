#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 55;
const int MOD = 1e9+7;
char grid[MAXN][MAXN];

signed main(){
    winton;
    vector<int> dice1(6), dice2(6);
    for (int i = 0; i < 6; i++){
        cin >> dice1[i];
    }
    for (int i = 0; i < 6; i++){
        cin >> dice2[i];
    }
    ld p1 = 0, equal = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (dice1[i] > dice2[j]) p1++;
            else if (dice1[i] == dice2[j])equal++;
        }
    }
    cout << fixed << setprecision(5) << p1/(36-equal) << endl;
}