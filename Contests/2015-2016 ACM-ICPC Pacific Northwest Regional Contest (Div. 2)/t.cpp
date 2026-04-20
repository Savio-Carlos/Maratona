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
    vector<int> t1(3);
    vector<int> t2(3);
    for (auto &u : t1) cin >> u;
    for (auto &u : t2) cin >> u;
    sort(all(t1));
    sort(all(t2));
    
    if ((t1[0] != t2[0]) || (t1[1] != t2[1]) || (t1[2] != t2[2])){
        cout << "NO" << endl;
        return 0;
    }

    auto check = [&] (int a, int b, int c){
        return (a*a + b*b == c*c);
    };

    if (check(t1[0],t1[1],t1[2]) || check(t1[0],t1[2],t1[1]) || 
        check(t1[1],t1[0],t1[2]) || check(t1[1],t1[2],t1[0]) || 
        check(t1[2],t1[1],t1[0]) || check(t1[2],t1[0],t1[1])){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

