#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {

        int n;
        cin >> n;
        int maior = n;
        int menor = 1;
        int i = 1;
        if (n%2==0) n--;
        while (n>=2){
            int p = pow(2,i);
            //cout << p << endl;
            if (i%2!=0){
                int nmenor = menor;
                while(nmenor+p <= maior) nmenor+=p;
                maior = nmenor;
            }
            else {
                int nmaior = maior;
                while(nmaior-p >= menor) nmaior-=p;
                menor = nmaior;
            }
            n/=2;
            i++;
        }
        if (i%2 == 0) cout << maior << endl;
        else cout << menor << endl;
    }
