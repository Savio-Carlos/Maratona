#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<vector<int>> visited(10, vector<int>(10));

    auto check = [&](int x, int y)-> bool{
        return (x < 10 and x >= 0 and y < 10 and y >= 0);
    };

    bool pos = true;
    while(n--){
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        r--;c--;
        if (d){
            for (int i = r; i < r+l; i++){
                if (!check(i,c) or visited[i][c]) pos = false;
                else visited[i][c] = 1;
            }
        }
        else {
            for (int j = c; j < c+l; j++){
                if (!check(r,j) or visited[r][j]) pos = false;
                else visited[r][j] = 1;
            }
        }
    }    
    if (pos) cout << "S" << endl;
    else cout << "N" << endl;
}