#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 1e17;
const int INF = INT_MAX;

vector<int> fib = {1, 1};
unordered_map<int,bool> memo;
vector<int> q;

bool dp(int n){
    if (n == 1) return true;
    if (memo.count(n)) return memo[n];
    for (int i = fib.size() - 1; i >= 2; --i) {
        if (n % fib[i] == 0) {
            if (dp(n / fib[i])) {
                q.push_back(i);
                return memo[n] = true;
            }
        }
    }
    return memo[n] = false;
}
signed main(){
    int n;
    cin >> n;   
    
    while (fib.back() <= MAX) {
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }

    if (!dp(n)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    //cout << fib[MAX-1] << endl;
    string ans = "";
    reverse(all(q));
    for (auto x : q){
        ans.append(x-1, 'A');
        ans.push_back('B');
    }
    cout << ans << endl;
}