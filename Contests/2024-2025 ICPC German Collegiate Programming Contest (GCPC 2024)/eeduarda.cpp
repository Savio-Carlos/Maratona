#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

const int MAXN = 301;
//nochange, even, flip
int dp[MAXN][MAXN][MAXN][2];
int n, nochange, even, flip;

map<int, int> e, f;
map<pair<char, int>, int> nc;

int pd(int a, int b, int c, int p){
    if(a + b + c == n){
        if((a + b + c)&1) return (p == 0);
        else return (p == 1);
    }

    if(dp[a][b][c][p] != -1) return dp[a][b][c][p];

    int pos = 0;
    //no change and next player can't win
    if(a < nochange && !pd(a+1, b, c, p)) pos = 1;

    if(!pos && b < even && !pd(a, b+1, c, 0)) pos = 1;

    if(!pos && c < flip && !pd(a, b, c+1, !p)) pos = 1;

    return dp[a][b][c][p] = pos;
}

void helper(char c, int v){
    cout << c << " " << v << endl;
}


void solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        char op; cin >> op;
        int val; cin >> val;
        if(op == '+'){
            if(val&1){
                flip++;
                f[val]++;
            }else{
                nochange++;
                nc[{op, val}]++;
            }
        }else{
            if(val&1){
                nochange++;
                nc[{op, val}]++;
            }else{
                even++;
                e[val]++;
            }
        }
    }
    int x; cin >> x;
    int turn = -1;
    if(pd(0, 0, 0, (x%2))){
        cout << "me\n";
        turn = 0;
    }else{
        cout << "you\n";
        turn = 1;
    }
    //no change, even, flip
    int a = 0, b = 0, c = 0, p = x%2;
    for(int i = 0; i < n; i++){
        //cout << turn << " " << a << " " << b << " " << c << endl;
        if(!turn){
            //cout << "entrou aqui primeiro\n";
            bool found = false;
            if(a < nochange && dp[a+1][b][c][p] == false){
                found = true;

                auto [res, _] = *nc.begin();
                helper(res.first, res.second);

                nc.erase(nc.begin());
                a++; 
            }

            if(!found && b < even && dp[a][b+1][c][0] == false){
                found = true;
        
                auto [val, _] = *e.begin();
                helper('*', val);

                e.erase(e.begin());
                p = 0;
                b++;
            }

            if(!found && c < flip && dp[a][b][c+1][!p] == false){
                found = true;
                auto [res, _] = *f.begin();

                helper('+', res);

                f.erase(res);
                c++;
                p = !p;
            }
            
            if(!found){
                if(a < nochange){
                    auto [res, _] = *nc.begin();
                    helper(res.first, res.second);

                    nc.erase(nc.begin());
                    a++; 
                }else if(b < even){
                    auto [val, _] = *e.begin();
                    helper('*', val);

                    e.erase(e.begin());
                    p = 0;
                    b++;
                }else if(c < flip){
                    auto [res, _] = *f.begin();

                    helper('+', res);

                    f.erase(res);
                    c++;
                    p = !p;
                }
            }
        }else{
            char op; cin >> op;
            int val; cin >> val;
            if(op == '+'){
                if(val&1){
                    c++;
                    f.erase(val);
                    p = !p;
                }
                else{
                    a++;
                    nc.erase({op, val});
                }
            }else{
                if(val&1){
                    a++;
                    nc.erase({op, val});
                }
                else{
                    e.erase(val);
                    b++;
                    p = 0;
                }
            }
        }
        turn = !turn;
    }
}

signed main(){
    //fastio;
    int t = 1;
    while(t--) solve();
    return 0;
}
