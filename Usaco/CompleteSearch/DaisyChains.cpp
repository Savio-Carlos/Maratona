#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
using ll = long long;
const int MAXL = LLONG_MAX;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
signed main() {
    //setIO("")
    int n; cin >> n; 
    vector<int> flowers(n); 
    for (auto &i : flowers) cin >> i;
    int ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            double media = 0;
            set<double> avg;
            for (int k = i; k <= j; k++){
                avg.insert(flowers[k]);
                media += flowers[k];
            }   
            if (avg.find(media/((j-i)+1)) != avg.end()) ans++;
            //cout << i << " ate " << j <<endl;
            //cout << ans << " media = " << media/((j-i)+1) << endl; 
        }
    }
    cout << ans << endl;
}