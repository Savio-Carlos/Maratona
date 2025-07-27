#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

void solve(){
    string s,aux="";
    cin>>s;
    int res = 0,auxnum=0;
    bool op = true;
    int cont = 0;
    
    for(int i = s.size()-1; i>=0 ; i--){
        aux += s[i];
        cont++;

        if(cont==3 || i == 0){
            cont = 0;
            reverse(aux.begin(),aux.end());
            auxnum = stol(aux);
            aux = "";
            if(op){
                res+=auxnum;
                op = false;
            }
            else {
                op = true;
                res-=auxnum;
            }
            auxnum = 0;
        }
    }
    int ans = llabs(res);
    if(ans%13==0){
        cout<<ans<<" "<<"YES"<<endl;
    }
    else {
        cout<<ans<<" "<<"NO"<<endl;
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}   
