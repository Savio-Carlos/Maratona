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

/*
k-esimo menor = o maior do intervalo
o tamanho minimo do palindrome tem que ser k-1
se tivermos k-1 caras iguais e eles forem o menor global entao e possivel

*/

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0, sum = 0;
    for (auto &u : a){
        cin >> u; 
        mx = max(u,mx);
        sum += u;
    } 
    if (sum&1 || (sum < mx*2)){
        cout << -1 << endl;
        return;
    }
    int half = sum/2;
    int idx = 0, cur = 0;
    for(; idx < n; idx++){
        if(cur + a[idx] > half) {
            idx--;
            break;
        }
        cur += a[idx];
    }
    int diff = abs(sum - cur*2);
    // debug(idx);
    // debug(diff);
    if (!diff){
        cout << 1 << endl;
        for (auto u : a) cout << u << " ";
        cout << endl;
        return;
    }
    vector<int> dim (n);
    dim[idx+1] = diff/2;
    a[idx+1] -= dim[idx + 1];
    diff /= 2;
    for(int i = n - 1; i > idx + 1 && diff; i--) {
        if(a[i] >= diff) {
            dim[i] = diff;
            a[i] -= diff;
            diff = 0;
        } else {
            dim[i] = a[i];
            diff -= a[i];
            a[i] = 0;
        }
    }

    cout << 2 << endl;
    // vdebug(a);
    for(auto u : a) cout << u << " ";
    cout << endl;
    // vdebug(dim);
    for(auto u : dim) cout << u << " ";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
