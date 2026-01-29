#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAXN = 1e6+7;
const int INF = 1e9;

double res(double a, double b, double c){
    return sqrt(abs(a-b)) + sqrt(abs(c-b)) + sqrt(abs(a-c));
}

signed main(){
    //fastio;
    int n; cin >> n;
    double prim, ultimo;
    cout << "? 1" << endl;
    cin >> prim;
    cout << "? " << n << endl;
    cin >> ultimo;

    //1 2 3 4
    int pos = 2;
    double melhor = (prim + ultimo)/2;
    //cout << melhor << endl;
    int l = 2, r = n-1, ans = 2;
    double cur = 0.0;
    while(l <= r){
        int meio = (l+r)/2;
        cout << "? " << meio << endl;
        double v; cin >> v;
        double x = res(prim, v, ultimo);
        if(x > cur){
            cur = x;
            ans = meio;
        }
        if(v < melhor) l = meio + 1;
        else r = meio - 1;
    }
    
    cout << "! " << 1 << " " << ans << " " << n << endl;
}