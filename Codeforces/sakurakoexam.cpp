#include <bits/stdc++.h>
using namespace std;

int main (){
    int t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (a == 0 && (b%2 == 0)){
            cout << "YES" << endl;
        }
        else if (b == 0 && (a%2 == 0)){
            cout << "YES" << endl;
        }
        else if (a%2 == 0 && a!=0){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}