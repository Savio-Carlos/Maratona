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
const int MAX = 100+7;
const int MOD = 1e9+7;

struct job{
    int d, s, idx;
};

void solve(){
    int n;
    cin >> n;
    vector<job> jobs;
    for (int i = 0; i < n; i++){
        int d, s;
        cin >> d >> s;
        job x = {d, s, i+1};
        jobs.push_back(x);
    }
    sort(jobs.begin(), jobs.end(), [&](job a, job b){
        int x = a.d * b.s;
        int y = a.s * b.d;
        if (x != y) return x < y;
        return a.idx < b.idx;
    });
    for (auto j : jobs) cout << j.idx << " ";
    cout << endl;
}

signed main() {
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}
