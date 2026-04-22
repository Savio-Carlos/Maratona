#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ans = false;

int main() {
    int t; 
    cin >> t;
    while (t--){
        ll n, k, diff;
        cin >> n >> k;
        diff = n - k;
      
        if (n%4 == 1 || n%4 == 2){
            ans = false;
        }
        else {
            ans = true;
        }

        if(diff >= 4){
            if (diff%4 == 0 || diff%4 == 3){
                ans = !ans;
            }
            else if (diff == 0 || diff == 3){
                ans = !ans;
            }
        }
        else {
            if (diff == 0 || diff == 3){
                ans = !ans;
            }
        } 

        if (!ans){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}

// 1 + 4 + 27 + 4096
// 1 5 32 288 3413 50069 par par impar impar
// 
