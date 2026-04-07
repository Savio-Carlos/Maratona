#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

signed main(){
    winton;
    int n, k;
    cin >> n >> k;

    vector<int> p(n), d(k), c(k);
    for (auto &u : p) cin >> u;
    for (auto &u : d) cin >> u;
    for (auto &u : c) cin >> u;

    vector<pair<int,int>> dc(k);
    for (int i = 0; i < k; i++) dc[i] = {d[i],c[i]};

    sort(all(p));
    sort(all(dc));

    auto check = [&](int mid) -> bool{
        int i = 0, j = 0;
        int cap = 0;
        while(i < n && j < k){
            if(cap == 0) cap = dc[j].second; 
            
            if(abs(p[i] - dc[j].first) <= mid){//colocar pessoa i no deposito j
                i++;
                cap--;
                // deposito cheio vai pro prox
                if (cap == 0) j++; 
            }
            else if(p[i] > dc[j].first){
                // deposito j esta muito a esquerda, pula ele
                cap = 0;
                j++;
            }
            else return false;// pessoa i ta mt longe do deposito, n da pra colocar
        }
        return i == n;
    };


    int l = 0, r = 1e10;
    int ans;

    while(l <= r){
        int mid = l + (r-l)/2;

        if(check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << endl;
}

/*
vou percorrendo as pessoas e mantenho uma queue dos depositos mais proximos
sempre comeca na pessoa mais a esquerda e deposito mais a esquerda
vou colocando as pessoas nesse deposito ate encher ou a distancia ficar maior que MID
se no fim eu coloquei todas as pessoas, entao e valido 
*/