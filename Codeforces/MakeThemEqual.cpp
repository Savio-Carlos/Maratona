#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t; cin >> t;
    while (t--){
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        set<char> letras;
        set<int> ans;

        for (int i = 0; i < n; i++){
            letras.insert(s[i]);
        }
        
        int pans = 0;
        for (int i = 1; i <= n; i++){
            bool uni = true;
            for (int j = i; j <= n; j+=i){
                if(s[j-1] != c){
                    uni = false;
                    break;
                }
            }
            if (uni){
                pans = i;
                break;
            }
        }

        if (letras.size() == 1 && letras.find(c) != letras.end()) cout << "0" << endl;
        else if (pans != 0){
            cout << "1" << endl;
            cout << pans << endl;
        } 
        else{
            cout << "2" << endl;
            cout << n << " " << n-1 << endl;
        }
       
    }
}