#include <iostream>
using namespace std;
using ll = long long;

bool col[16], diagonal[16], diagonal2[16], reserved[8][8];
ll ways = 0;

void search(ll r){//index da linha a ser procurada
    if (r == 8){//percorrido tudo
        ways++;
        return;
    }
    for (ll c = 0; c < 8; c++){
        if (col[c] || diagonal[r+c] || diagonal2[r-c+7] || reserved[r][c]){//r+c diagonal comecando do 00, r-c+7 diagonal comecando do 07, como e xadrezo maximodequadrado e 8
        continue;
        }
    col[c] = diagonal[r+c] = diagonal2[r-c+7] = true;
    search(r+1);
    col[c] = diagonal[r+c] = diagonal2[r-c+7] = false;
    }
}


int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i <16; i++ ){
        col[i] = diagonal2[i] = diagonal[i] = false;
    }

    string x;

    for(int i = 0; i <8; i++ ){
        cin >> x;
        for(int j = 0; j <8; j++ ){
            reserved[i][j] = x[j] != '.' ;//se for diferente de ponto (asterisco) vai reservar
        }
    }


    search(0);
    cout << ways;

    return 0;
}