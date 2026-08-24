
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

string d[] = {"010","110","111","101","100","000","001","011"};

int main(){
    string s;
    cin >> s;
    int st = 0;
    for (int i = 0; i < 8; i++){
        if (d[i] == s){
            st = i;
            break;
        }
    }
    cout << d[st] << endl;
    for (int i = (st + 1) % 8; i != st; i = (i+1)%8){
        cout << d[i] << endl;
    }
    cout << d[st] << endl;
}