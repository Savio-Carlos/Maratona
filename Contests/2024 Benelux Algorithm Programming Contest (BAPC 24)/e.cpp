#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAXN = 1e6+7;
const int INF = 1e9;

bool solve(int melhor, int x, int otimo){
    if(abs(x - otimo) < abs(melhor - otimo)){
        return true;
    }
}

signed main(){
    //fastio;
    int n; cin >> n;
    int prim, ultimo;
    cout << "? 1" << endl;
    cin >> prim;
    cout << "? " << n << endl;
    cin >> ultimo;

    //1 2 3 4
    int pos = 2;
    int melhor = (prim + ultimo)/2;
    //cout << melhor << endl;
    int l = 1, r = n-1, ans = 0;
    while(l < r){
        int meio = l + (r-l)/2;
        ans = meio;
        cout << "? " << meio << endl;
        int v; cin >> v;
        if(v >= melhor) r = meio - 1;
        else l = meio + 1;
    }
    
    cout << "! " << 1 << " " << ans << " " << n << endl;
}