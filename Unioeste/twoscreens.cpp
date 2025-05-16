#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        int ans = s.length() + t.length();
        int menor = min(s.length(), t.length());
        int aux = 0;
        for (int i = 0; i < menor; i++){
            if(s[i]!=t[i]) break;
            aux++;
        }
        if (aux){
            ans-=aux;
            ans++;
        }
        cout << ans << endl;
    }
}