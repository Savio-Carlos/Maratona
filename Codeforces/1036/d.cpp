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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &u : a) cin >> u; 
    vector<int> sorted = a;
    sort(all(sorted));
    int kesimo = sorted[k-1];
    vector<int> b;
    for (int i = n-1; i >= 0; i--){
        if (a[i] <= kesimo) b.push_back(a[i]);
    }
    // vdebug(a);

    int l = 0, r = b.size()-1;
    set<int> removes;
    while (l < r){
        // debug(l);
        // debug(r);
        if(b[l] == b[r]){
            l++;
            r--;
            continue;
        }

        if (b[l] == kesimo){
            removes.insert(l);
            l++;
            continue;
        }

        if (b[r] == kesimo){
            removes.insert(r);
            r--;
            continue;
        }
        cout << "NO\n";
        return; 
    }
    vector<int> ans;
    for (int i = 0; i < b.size(); i++){
        if (removes.find(i) != removes.end()) continue;
        ans.push_back(b[i]);
    } 
    // vdebug(ans);
    if (ans.size() < k-1){
        cout << "NO\n";
        return; 
    }
    cout << "YES\n";
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
