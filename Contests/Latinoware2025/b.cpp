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
    string s;
    getline(cin,s);
    // cout << s;
    cout << "Qual o nome da sua equipe?" << endl;
    cout << "Nos chamamos " << s << "." << endl;
    cout << "Me perdoe, poderia repetir qual o nome da sua equipe?" << endl;
    cout << "Somos a equipe " << s << "." << endl;
       cout << "Me desculpe novamente. Poderia repetir mais uma vez, por favor?" << endl;
    cout << "SOMOS A EQUIPE ";
    for (auto &c : s){
        if (c >= 'a' && c <= 'z') c = toupper(c);
        cout << c;
    }
    cout << "!!!" << endl;
    cout << "Ah, agora entendi. Boa prova!" << endl;
}