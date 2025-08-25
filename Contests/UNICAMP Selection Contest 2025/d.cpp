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
const int MAX = 2e5+7;
const int MOD = 1e9+7;

signed main(){
    winton;
    int n, lx;
    cin >> n >> lx;
    vector<int> a(n);
    priority_queue<int> menor, maior;
    for (auto &u : a){
        cin >> u;
        if (u >= 0) maior.push(-u);
        else menor.push(-u);
    } 
    vector<int> sorted;
    int cur = 0;

    while(sorted.size() != n){
        while (!maior.empty() && cur + -maior.top() < lx){
            cur += -maior.top();
            sorted.push_back(-maior.top());
            maior.pop();
        }
        while (!menor.empty() && cur + -menor.top() >= -lx){
            cur += -menor.top();
            sorted.push_back(-menor.top());
            menor.pop();
        }
        //debug(cur);
    }

    //vdebug(sorted);
    int sum = 0;
    bool pos = true;
    for (auto u : sorted){
        sum += u;
        //debug(sum);
        if (sum >= lx || sum < -lx) pos = false;
    }
    if (pos) {
        cout << "S" << endl;
        for (auto u : sorted) cout << u << " ";
    }
    else cout << "N" << endl;

}