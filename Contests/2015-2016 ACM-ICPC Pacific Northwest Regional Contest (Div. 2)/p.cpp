#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    winton;
    string s;
    cin >> s;
    map<char,int> cnt;
    for (auto c : s) cnt[c]++;
    vector<int> a;
    for(auto [_, c] : cnt) a.push_back(c);
    sort(rall(a));
    int sum = accumulate(all(a), 0LL);
    int mn1 = a[0];
    int mn2 = a.size() > 1 ? a[1] : 0;
    cout << sum - mn1 - mn2 << endl;
}

