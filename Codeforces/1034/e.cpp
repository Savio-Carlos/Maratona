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
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin >> n;
    map<int,int> freq;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    int o = -1;
    for (int i = 0; i <= n+1; i++){
        if (freq.count(i) == 0) {
            o = i;
            break;
        }
    }
    vector<int> ans(n+1, 0);
    for (int i = 0; i <= o; i++){
        int f;
        if (freq.count(i)){
            f = freq[i];
        } 
        else f = n;
        ans[f]++;
        ans[min(n,n-i+1)]--;
        /*
                for (int k = 1; k < n; k++){
            if (f <= k && (n - k) > i) ans[k]++;
        
        }
            tentar achar os o intervalo de k's em que esse if e valido
            r vai ser f, pois isso so vale quando f <= k entao depois disso sempre e falso
            lado esquerdo vai ser i
        */
    }
    ans[0] = 1;
    //for (auto u : ans) cout << u << " ";
    for (int i = 1; i <= n; i++) ans[i] += ans[i-1];
    //cout << endl;
    ans[n] = 1;
    for (auto u : ans) cout << u << " ";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
