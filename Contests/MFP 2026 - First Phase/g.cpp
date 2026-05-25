#include <bits/stdc++.h>
using namespace std;

#define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
#define int long long

signed main(){
    winton;
    int n;
    cin >> n;
    if (n%3) cout << "GANHA\n";
    else cout << "PERDE\n";
}