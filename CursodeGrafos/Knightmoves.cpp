#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,int>> moves = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool valid(int x, int y){
    return (x>=0 && x<=7 && y>=0 && y<=7);
}

pair<int,int> conversao(string s){
    int x = s[0] - 'a';
    int y = s[1] - '1';
    return {x,y};
}

int bfs(pair<int,int> comeco, pair<int,int> fim){
    if (comeco == fim) return 0;
    int passos = 0;
    queue<pair<int,int>> q;
    bool visitados[8][8] = {};

    q.push(comeco);
    visitados[comeco.first][comeco.second] = true;

    while (!q.empty()){
        ++passos;
        int n = q.size();
        
        for(int i = 0; i < n; i++){
            pair<int,int> atual = q.front();
            q.pop();

            for (const auto& move : moves) {
                int novox = atual.first + move.first;
                int novoy = atual.second + move.second;

                if (valid(novox,novoy) && !visitados[novox][novoy]){
                    if(make_pair(novox,novoy) == fim)return passos;
                    q.push({novox,novoy});
                    visitados[novox][novoy] = true;
                }
            }
        }
    }
}

int main() {
    string move1, move2;
    while(cin >> move1 >> move2){
        pair<int, int> inicio = conversao(move1);
        pair<int, int> fim = conversao(move2);

         cout << "To get from " << move1 << " to " << move2 << " takes " << bfs(inicio,fim) << " knight moves." << endl;
    }
}