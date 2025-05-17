#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int,int> mp;
    for (auto &u : a) cin >> u;
    for (int i = 0; i < n; i++){ 
        cin >> b[i];
        mp[b[i]]++;
    }
    set<int> solutions;
    for (int i = 0; i < n; i++){
        if (a[0] + b[i] > 0) solutions.insert(a[0] + b[i]);
        if (a[0] - b[i] > 0) solutions.insert(a[0] - b[i]);
    }
    for (int i = 1; i < n; i++) {
        set<int> next;
        for (int u : solutions) {
            if (mp.count(abs(a[i] - u))) next.insert(u);
        }
        solutions.swap(next);
    }
    for (auto u : solutions) { if (u <= 1e9) cout << u << endl;}
}   