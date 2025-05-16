#include <bits/stdc++.h>
using namespace std;


int main(){
    string str; cin >> str;
    int n = str.length();
    int r = 0, aux = 0;

    for (int i = 0; i < n; i++){
        if (str[i] == str[i+1]) {
        r++;
            if (r > aux) aux = r;    
        }
        else r = 0;
    }
    aux++;
    cout << aux << endl;

    return 0;
}