#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define pb(x) push_back(x)
const int MAXL = 1e9+7;

signed main (){_
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        
        vector<string> arr (n);
        vector<int> zeros;
        
        for (auto &i : arr) cin >> i;
        int sum_digits = 0;
        for (int i = 0; i < n; i++){
            string s = arr[i];
            sum_digits += s.length();
            if (s[s.length()-1] == '0'){
                int neglect = 0;
                int j = s.length() - 1;
                while (s[j] == '0'){
                    neglect++;
                    j--;
                }
                zeros.push_back(neglect);
            }
        }
        
        sort(rall(zeros));
        for (int i = 0; i < (zeros.size()); i+=2){
            sum_digits -= (zeros[i]);
        }
        cout << (sum_digits >= (m+1) ? "Sasha" : "Anna") << endl;
    }

}