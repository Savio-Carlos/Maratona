#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;


signed main(){
    fastio;
    map<string,int> cartas;
    cartas["Onca"] = 6;
    cartas["Engenheiro"] = 5;
    cartas["Fotografo"] = 4;
    cartas["Protetor"] = 7;
    cartas["Flamingo"] = 3;
    cartas["Capivara"] = 8;
    cartas["Iguazu"] = 6;
    cartas["Quati"] = 2;
    cartas["Ponte"] = 3;
    cartas["Pinguim"] = 3;
    cartas["Mboi"] = 4;
    cartas["Roda"] = 1;
    int poderj1 = 0, poderj2 = 0;
    int vitorias1 = 0, vitorias2 = 0;
    int q1, q2;
    //Esquerda
    int j1l = 0, j2l = 0;
    cin >> q1;
    for (int i = 0; i < q1; i++){
        string s;
        cin >> s;
        j1l += cartas[s];
        if (s == "Roda") j1l += (q1-1);
        if (s == "Iguazu" && q1 >= 4) j1l += 6;  
    }
    poderj1 += j1l;

    cin >> q2;
    for (int i = 0; i < q2; i++){
        string s;
        cin >> s;
        j2l += cartas[s];
        if (s == "Roda") j2l += (q2-1);
        if (s == "Iguazu" && q2 >= 4) j2l += 6;  
    }
    poderj2 += j2l;
    if (j2l > j1l) vitorias2++;
    else if (j1l > j2l) vitorias1++;


    //Central
    int j1c = 0, j2c = 0;
    cin >> q1;
    for (int i = 0; i < q1; i++){
        string s;
        cin >> s;
        j1c += cartas[s];
        if (s == "Roda") j1c += (q1-1);
        if (s == "Iguazu" && q1 >= 4) j1c += 6;  
        if (s == "Mboi") j1c += 5;
    }
    poderj1 += j1c;

    cin >> q2;
    for (int i = 0; i < q2; i++){
        string s;
        cin >> s;
        j2c += cartas[s];
        if (s == "Roda") j2c += (q2-1);
        if (s == "Iguazu" && q2 >= 4) j2c += 6;  
        if (s == "Mboi") j2c += 5;
    }
    poderj2 += j2c;
    if (j2c > j1c) vitorias2++;
    else if (j1c > j2c) vitorias1++;

        //Direita
    int j1r = 0, j2r = 0;
    cin >> q1;
    for (int i = 0; i < q1; i++){
        string s;
        cin >> s;
        j1r += cartas[s];
        if (s == "Roda") j1r += (q1-1);
        if (s == "Iguazu" && q1 >= 4) j1r += 6;  
    }
    poderj1 += j1r;

    cin >> q2;
    for (int i = 0; i < q2; i++){
        string s;
        cin >> s;
        j2r += cartas[s];
        if (s == "Roda") j2r += (q2-1);
        if (s == "Iguazu" && q2 >= 4) j2r += 6;  
    }
    poderj2 += j2r;
    if (j2r > j1r) vitorias2++;
    else if (j1r > j2r) vitorias1++;

    if (vitorias1 > vitorias2) cout << "Jogador 1" << endl;
    else if (vitorias2 > vitorias1) cout << "Jogador 2" << endl;
    else {
        if (poderj1 > poderj2) cout << "Jogador 1" << endl;
        else if (poderj2 > poderj1) cout << "Jogador 2" << endl;
        else cout << "Empate" << endl;
    }

}