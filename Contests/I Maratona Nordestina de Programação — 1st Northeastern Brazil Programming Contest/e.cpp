#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(),x.end()

signed main(){
    // fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    iota(all(a),1);

    for (int _ = 1; _ <= 8; _++){
        if (a.size() == 1) break;
        int m = a.size();
        int div = (m+1)/3;

        vector<int> t1, t2, t3;
        for (int i = 0; i < m; i++){
            if (i < div) t1.push_back(a[i]);
            else if (i < div*2) t2.push_back(a[i]);
            else t3.push_back(a[i]);
        }
      
        cout << "? " << div << " ";
        for (int i = 0; i < div*2; i++) cout << a[i] << " "; 
        cout << endl;

        char ans;
        cin >> ans;

        if (ans == 'E') a = t1;
        else if (ans == 'D') a = t2;
        else if (ans == 'I') a = t3;

    }
    cout << "! " << a[0] << endl;
} 