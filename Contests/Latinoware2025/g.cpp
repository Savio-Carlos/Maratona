#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

signed main(){
    vector<pair<ld,int>> div(2);
    vector<ld> v(2);
    vector<ld> vel(2);
    cin >> div[0].second >> v[0] >> vel[0];
    cin >> div[1].second >> v[1] >> vel[1];
    div[0].first = v[0] / vel[0];
    div[1].first = v[1] / vel[1];
    sort(all(div));
    cout<<div.front().second<<endl;
}