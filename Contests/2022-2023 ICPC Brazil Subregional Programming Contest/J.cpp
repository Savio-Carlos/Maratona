#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;

signed main(){
    winton;
    vector<int> qtd(11, 4);
    qtd[10] = 16;

    int n, joao = 0, maria = 0;
    cin >> n;
    for (int i = 0; i<2; i++){
        int a; cin >> a;
        if (a > 10) a = 10;
        qtd[a]--;
        joao+=a;
    }
    for (int i = 0; i<2; i++){
        int a; cin >> a;
        if (a > 10) a = 10;
        qtd[a]--;
        maria+=a;
    }
    while(n--){
        int a;
        cin >> a;
        if (a > 10) a = 10;
        qtd[a]--;
        joao+=a;
        maria+=a;
    }
    
    for (int i = 1; i <= 10; i++){
        if(qtd[i]==0)continue;
        if ((maria+i)==23 || (maria+i <= 23 && joao+i > 23)){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
//cout << joao << " " << maria << endl;
}
