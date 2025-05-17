#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> str;
vector<int> numM;
vector<int> numN;
string originalM;
string originalN;

void funcao (string alteracao,int indice, char troca, int n){
    alteracao[indice] = troca;

    for (int i = indice; i < n; i++){
        if (alteracao[i] == '*'){
            funcao(alteracao, i, '1', n);
            funcao(alteracao, i, '0', n);
            break;
        }
        if (i+1 == n){
        str.push_back(alteracao);
    }
    }
}

int main(){
    string alteracao;
    cin >> originalM >> originalN;
    alteracao = originalM;

    int n = originalM.length();
    
    funcao(alteracao, 0, originalM[0], n);

    for (int i = 0; i < int(size(str)); i++){
        cout << str[i] << endl;
    }

    return 0;

}