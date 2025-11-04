#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main (){
    fastio;
    int n;
    cin >> n;
    vector<vector<int>>m(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }


    // quantidade de doadores, posicao x, y
    // set<pair<int,pair<int,int>>> greedy;
    priority_queue<pair<int,pair<int,int>>> greedy;

    // doador de i, j
    vector<vector<set<pair<int,int>>>> doador(n,vector<set<pair<int,int>>>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(!m[i][j]){
                for(int k=0;k<n;k++){
                    if(m[i][k]>1){
                        doador[i][j].insert({i,k});
                    }
                }

                for(int k=0;k<n;k++){
                    if(m[k][j]>1){
                        doador[i][j].insert({k,j});
                    }
                }
            }

            greedy.push({-doador[i][j].size(),{i,j}});
            // greedy.insert({doador[i][j].size(),{i,j}});

        }
    }

    while(!greedy.empty()){

        pair<int,int> receba = *greedy.begin();

        int recebax = receba.first;
        int recebay = receba.second;

        for(auto [tomex, tomey]:doador[recebax][recebay]){
            if(m[tomex][tomey] > 1) {
                m[tomex][tomey]--;
                break;
            }
        }

        greedy.erase(greedy.begin());
    }


}