#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, k;
    map<int, int> m;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int i = 0;
    int j = 0;
    int s = 0;
    int ans = 0;
    int curr = 0;
    bool alterado = false;

    while(j < n){     
        if(!alterado){
            s += v[j];
            m[v[j]] ++;   
            if(m[v[j]] % 2 == 0) curr ++;             
        }                              

        if(s > k){            
            s -= v[i];
            m[v[i]] --;
            curr -= m[v[i]] % 2;            

            i ++;            

            if(i > j){
                j= i;
                alterado = false;
            } else{
                alterado = true;
            }
            ans = max(ans, curr);

        } else{                              
            alterado = false;                                               
            j ++;

            ans = max(ans, curr);
        }        
    }

    cout << ans << endl;

    
}