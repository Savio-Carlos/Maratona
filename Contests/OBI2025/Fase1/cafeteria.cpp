#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cur = 0;
    while (cur+d < c){
        int leite = c - cur;
        if (leite >= a && leite <= b){
            cout << "S" << endl;
            return 0;
        }       
        cur += d;
    }
    cout << "N" << endl;
}