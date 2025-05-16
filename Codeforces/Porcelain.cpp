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


int n, m, dp[MAXN][MAXM], value[MAXN][MAXN];
vector<vector<int>> shelves;
int brute(int i, int k){
    //cout << "k: " << k << endl;
    if (i == n) {
        if (k == m) return 0;
        else return INT_MIN;
    }
    if(dp[i][k] != -1) return dp[i][k];

    int ans = 0;
    for (int j = 0; j <= min((int)shelves[i].size(), m-k); j++){
        //cout << i << " " << k << " " << value[i][j] << endl;
        ans = max(ans, brute(i+1, k+j) + value[i][j]);
        //cout << i << " " << k+j << " " << ans << endl;
    }

    return dp[i][k] = ans;
}

signed main(){  
    winton;
    cin >> n >> m;
    shelves.resize(n);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        shelves[i].resize(a);
        for (int j = 0; j < a; j++){
            cin >> shelves[i][j];
        }
    }
 
    for (int i = 0; i < n; i++){
        int sz = shelves[i].size();

        vector<int> prefix(sz + 1, 0), suffix(sz + 1, 0);

        for (int j = 1; j <= sz; j++){
            prefix[j] = shelves[i][j-1] + prefix[j-1];
        }
        for (int j = 1; j <= sz; j++){
            suffix[j] = shelves[i][sz-j] + suffix[j-1];
        }

        for (int x = 0; x <= sz; x++){
            int best = 0;
            for (int r = 0; r <= x; r++){
                int cur = prefix[r] + suffix[x-r];
                best = max(best,cur);
            }
            value[i][x] = best;
        }
        
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= shelves[i].size(); j++){
            //cout << value[i][j] << " ";
        }
        //cout << endl;
    }

    memset(dp, -1, sizeof(dp));
    int ans = brute(0,0);
    cout << ans << endl;

}