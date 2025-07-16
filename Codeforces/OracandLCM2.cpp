#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 200007;
const int INF = LLONG_MAX;

int spf[MAX];
vector<int> min1(MAX, INF), min2(MAX, INF); 

void build(){
    for (int i = 2; i < MAX; i+=2) spf[i] = 2;
    for (int i = 3; i < MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i < MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

void factorize(int x){
    while (x > 1){
        int cnt = 0;
        int p = spf[x];
        while(x%p == 0){
            x/=p;
            cnt++;
        } 
        if (cnt < min1[p]) {
            min2[p] = min1[p];
            min1[p] = cnt;
        }
        else if (cnt < min2[p]) min2[p] = cnt;
    }
}

int fastexpo(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base);
        base = (base * base) ;
        exp /= 2;
    }
    return res;
}

signed main(){
    winton;
    build();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        factorize(x);
    } 
    int ans = 1;
    for (int i = 2; i < MAX; i++){
        if (min2[i] != INF) ans*= fastexpo(i,min2[i]);
    }
  
    cout << ans << endl;
}