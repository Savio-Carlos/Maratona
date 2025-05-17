#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;

signed main(){
    winton;
    string s;
    cin >> s;
    if (s == "XXO" || s == "OXX") cout << "Alice" << endl;
    else if (s == "XOX") cout << "*" << endl;
    else  cout << "?" << endl;
}