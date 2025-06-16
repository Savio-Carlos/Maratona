#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n, a, b, k;
    cin >> n >> a >> b;
    vector<int> stair(n);
    bool ans = false;
    for (int i = 0; i < n; i++){
        cin >> stair[i];
        if(i)stair[i]+=stair[i-1];
    }
    cin >> k;
    for (int i = 0; i < n; i++){
        if (i == k-1)continue;
        if (stair[i]+a >= stair[k-1]+b){
            cout << "SIM" << endl;
            cout << i+1 << endl;
            return 0; 
        }
    }
    cout << "NAO" << endl;
}