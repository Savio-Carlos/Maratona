#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAXN = 1e6+7;
//contagem de quantos divisores acesos esse primo p tem
int cnt[MAXN], spf[MAXN], visited[MAXN];

/*
we find the smallest prime factor for each guy 
*/ 

//menor fator primo
void mfp(){
    iota(spf, spf+MAXN, 0);
    for(int i = 2; i*i < MAXN; i++){
        if(spf[i] == i){
            for(int j = i*i; j < MAXN; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> factorize(int x){
    vector<int> primos;
    while(x > 1){
        int p = spf[x];
        primos.push_back(p);
        while(!(x%p)) x/=p;
    }
    return primos;
}

int main(){
    fastio;
    int n; cin >> n;
    priority_queue<pair<int, int>> pq;
    mfp();
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        vector<int> primos = factorize(x);
        int toggle = 0;
        if(visited[x]) toggle = -1;
        else toggle = 1;
        visited[x] = (1^visited[x]);
        for(auto p : primos){
            cnt[p] += toggle;
            pq.push({cnt[p], p});
        }

        int cur = 0;
        while(!pq.empty()){
            auto [c, p] = pq.top();
            if(cnt[p] == c){
                cur = cnt[p];
                break;
            }
            pq.pop();
        }
        cout << cur << endl;
    }
}