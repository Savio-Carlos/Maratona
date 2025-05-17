#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 2e5;

int main (){
    minecraft;

    int n,m,c=0;

    cin>>n>>m;

    unordered_map<int,int> mp;
    mp.reserve(n*2);
    int matrizpelada=0;

    for(int l = 0; l<n;l++){
        int mask = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < m;j++){
                char c;
                cin >> c;
                if (c == 'X'){
                    mask |= (1<<(i*m+j));
                }
                
            } 
        }
        mp[mask]++;
    }
    matrizpelada = mp[0];
    c+= matrizpelada*(n-matrizpelada);
    c+=(matrizpelada*(matrizpelada-1))/2;
    for(auto &u:mp){
        if(u.first!= 0 && u.second>1){
            c+=(u.second*(u.second-1))/2;
        }
        //cout << u.second << " ";
    }
    // cout << endl;
    // cout << "peladas: " << matrizpelada << endl;
    cout<<c<<endl;

}