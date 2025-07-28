#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 1e6+7;
const int MOD = 1e9+7;

int n, m = 0, ans = 1, cnt[MAX], freq[MAX];

void getdivisors(){
    for (int i = 2; i <= m; ++i) {
        for (int j = i; j <= m; j += i) {
            if (freq[j] > 0) {
                cnt[i] += freq[j];
            }
        }
    }
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
        m = max(a[i], m);
    }
    getdivisors();
    for (int i = m; i >= 0; i--){
        if (cnt[i] > 1){
            ans = i;
            break;
        } 
    }
    cout << ans << endl;
}