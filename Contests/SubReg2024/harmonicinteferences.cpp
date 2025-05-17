#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> str;
vector<int> numM;
vector<int> numN;
string originalM;
string originalN;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

void funcao(string alteracao, int indice, char troca, int n)
{
    alteracao[indice] = troca;

    for (int i = indice; i < n; i++)
    {
        if (alteracao[i] == '*')
        {
            funcao(alteracao, i, '1', n);
            funcao(alteracao, i, '0', n);
            break;
        }
        if (i + 1 == n)
        {
            str.push_back(alteracao);
        }
    }
}

int main()
{
    string alteracao;
    cin >> originalM >> originalN;
    alteracao = originalM;

    int n = originalM.length();

    funcao(alteracao, 0, originalM[0], n);

    //for (int i = 0; i < int(size(str)); i++)
    //{
        //int n = stoi(str[i]);
        //numM.push_back(binaryToDecimal(n));
    //}

    for (int i = 0; i < int(size(str)); i++)
    {
       // cout << str[i] << endl;
    }

    return 0;
}