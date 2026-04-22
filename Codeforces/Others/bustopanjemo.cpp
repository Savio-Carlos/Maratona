#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, r, ans = 0, sobra = 0;
        cin >> n >> r;
        vector<int> fam(n);
        for (int i = 0; i < n; i++){
            cin >> fam[i];
            sobra += (fam[i]%2);
            if (fam[i] >= 2){
                if (fam[i] %2 == 0){
                    ans+=fam[i];
                }
                else {
                    ans += fam[i]-1;
                }
                r-= fam[i]/2;
                
            }
        }
        
        while (sobra > r){
            sobra-=2;
            r--;
        }
        ans += sobra;

        cout << ans << endl;
    }
}