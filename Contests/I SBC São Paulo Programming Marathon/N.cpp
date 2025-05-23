#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 1e6+7;

/*
calcular os spf dos numeros
para cada numero ver os fatores primos que dividem ele e adicionar +1 no contador
quando ver o numero de novo eu retiro do contador desses primos
pra cada numero tenho que ver quais dos fatores dele tem o contador mais alto
ou se algum fator anterior e maior
*/

int n, spf[MAX], cnt[MAX];
bool visited[MAX];

void build(){
    for (int i = 2; i < MAX; i+=2) spf[i] = 2;
    for (int i = 3; i < MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i <= MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

vector<int> factorize(int x){
    vector<int> primes;
    while (x > 1){
        int p = spf[x];
        primes.push_back(p);
        while(x%p == 0) x/=p;
    }
    return primes;
}

signed main(){
    winton;
    cin >> n;
    build();
    multiset<int> ans;
    for (int i = 0; i < MAX; i++) ans.insert(0);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        vector<int> primos = factorize(a); 
        for (auto u : primos){
            ans.erase(ans.find(cnt[u]));
            if (!visited[a]) cnt[u]++;
            else cnt[u]--;
            ans.insert(cnt[u]);
        }
        visited[a] ^= 1; 
        cout << *ans.rbegin() << endl;
    }
}