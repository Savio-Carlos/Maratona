#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAXN = 5*(1e5)+7;
int arr[MAXN];
vector<int> menores;
unordered_set<int> divisors[MAXN];


//aq acho todos os divisores primos de cada numero
void fact(int idx){
    int x = arr[idx];
    divisors[idx].clear();
    while(x > 1){
        int p = menores[x];
        divisors[idx].insert(p);
        while(!(x%p)) x /= p;
    }
}

signed main(){
    int n, k; cin >> n >> k;
    arr[0] = k;
    int maximo = arr[0];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        maximo = max(arr[i], maximo);
    }
    menores.resize(maximo+1, 0);
    for(int i = 2; i <= maximo; i++){
        if(menores[i] == 0){
            for(int j = i; j <= maximo; j += i) 
                if(menores[j] == 0) menores[j] = i;
        }
    }

    fact(0);
    int ans = -1, res = 1;
    // cout << "divisores de k\n";
    // for(auto u : divisors[0]){
    //     cout << u << " ";
    // }
    // cout << endl;
    for(int i = 1; i <= n; i++){
        fact(i);
        unordered_set<int> st;
        st = divisors[0];
        //cout << "divisores de i " << arr[i] << endl;
        for(auto u : divisors[i]){
            //cout << u << " ";
            st.insert(u);
        }
        //cout << endl;
        if((int) st.size() > ans){
            ans = (int) st.size();
            res = i;
        }
    }
    cout << res << endl;
}