#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)


signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int x, y, z, k;
        cin >> x >> y >> z >> k;
        vector<int> prime;
        int n = k;
        for (int i = 2; i <= sqrt(n); i++){
            if (n%i == 0)
            while(n%i == 0){
            prime.push_back(i);
            n = n/i;
            }
        }
        if (n > 1) prime.push_back(n);
        int a,b,c;

        sort(rall(prime));
        if (prime.size() >= 3){
            a = prime[0], b = prime[1], c = prime[2];
            for (int i = 3; i < prime.size(); i++){
                int aux = min ({a,b,c});
                if (aux == a) a*=prime[i];
                else if (aux == b) b*=prime[i];
                else if (aux == c) c*=prime[i];
            }
        }
        else if (prime.size() == 2){
            a = prime[0], b = prime[1], c = 1;
        }
        else {
            a = k, b = 1, c = 1;
        }
        
        //cout << a << b << c  << endl;
        vector<int> ori;
        vector<int> dup;
        ori.push_back(x);
        ori.push_back(y);
        ori.push_back(z);
        dup.push_back(a);
        dup.push_back(b);
        dup.push_back(c);
        sort(rall(ori));
        sort(rall(dup));
        int d1 = max(0LL, ori[0]-dup[0]+1);
        int d2 = max(0LL, ori[1]-dup[1]+1); 
        int d3 = max(0LL, ori[2]-dup[2]+1);
        cout << d3 * d1 * d2 << endl;
    }
}