#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &u : a) cin >> u;
    int l;
    cin >> l;
    int ans = 0;
    for (auto u : a){
        if (u > l) ans++;
    }
    if (ans >= n) cout << "SIM\n";
    else cout << "NAO\n";
}