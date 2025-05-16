#include <bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;
    int n, cnt = 0;

    cin >> n >> str1 >> str2;

    for(int i = 0; i < n; i++){
        if (str1[i] == str2[i]) cnt++;
    }
    
    cout << cnt << "\n" << endl;

    return 0;
}