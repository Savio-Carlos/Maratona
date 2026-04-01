#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)


signed main(){
    winton;
    int n;
    cin >> n;
    map<int,string> ans;
    ans[1] = "walk";
    ans[2] = "no";
    ans[3] = "no";
    ans[4] = "no";
    ans[5] = "yes";
    ans[6] = "yes";
    ans[7] = "backwards";
    ans[8] = "7";
    cout << ans[n] << endl;
}