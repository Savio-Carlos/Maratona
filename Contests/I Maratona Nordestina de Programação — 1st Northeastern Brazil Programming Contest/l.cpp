#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int main(){
    int n;
    cin >> n;
    if (n%4 == 0 or n%4 == 3) cout << "PAR" << endl;
    else cout << "IMPAR" << endl;
}