#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            arr[i] = s[i] - '0';
        }

        for (int i = 0; i < n; i++){
            int mx = arr[i];
            int it;
            for (int j = 0; j < 9 && i+j < n; j++){
                if (arr[i+j] - j > mx){
                    mx =arr[i+j]-j;
                    it = i+j;
                }
                
            }
            arr[i] = mx;
        }
         for (int i = 0; i < n; i++){
            cout << arr[i];
         }
         cout << endl;
    }
}