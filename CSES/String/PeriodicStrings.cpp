#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

vector<int> kmp(string s){
    int n = s.size(), pfxlen = 0;
    vector<int> a(n, 0);
    for (int i = 1; i < n; i++){
        if (s[i] == s[pfxlen]) a[i] = ++pfxlen;
        else if (pfxlen){
            pfxlen = a[pfxlen-1];
            i--;
        }
        else a[i] = 0;
    }
    return a;
}

void solve(){
    string s;
    cin >> s;
    vector<int> a = kmp(s);  
    int n = s.size();
    int p = n - a[n-1];
    if (n % p == 0) cout << p << endl;
    else cout << n << endl;
}

signed main(){
    winton;
    int t = 1;
    cin >> t;
    while(t--) solve();
}

