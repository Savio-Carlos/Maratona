#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--){
        ll n;
        string s;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i ++){
            cin >> arr[i];
        }
        cin >> s;

        int cnt = 0;
        
        for (int i = 1; i <= n; i ++){
            int j = arr[i-1];
            if (s[j-1] == '0' && i == j){
                cout << '1';
                continue;
            }
            do{
                if(s[arr[j]] == '0') cnt++;
                j = arr[j];
            } while (arr[j] != i);
            cout << cnt;
        }
        cout << endl;
    }

}