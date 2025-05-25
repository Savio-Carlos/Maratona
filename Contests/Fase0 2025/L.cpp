#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n;
    cin >> n;
    n*=8;
    n*=1e6;
    int ans = 1;
    int cnt = 0;
    while (ans < n){
        ans*=2;
        cnt++;
    }
    cout << cnt << endl;
}