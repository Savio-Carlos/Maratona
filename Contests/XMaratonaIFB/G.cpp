#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;

signed main() {
    winton;
    string s;
    cin >> s;
    if (s == "Estados") {
        string trash;
        cin >> trash;
        cout << "hen ou chicken" << endl;
    }
    else if (s == "Alemanha") cout << "huhn" << endl;
    else if (s == "Angola") cout << "to fraca" << endl;
    else if (s == "Japao") cout << "niwatori" << endl;
    else if (s == "Russia") cout << "kuritsa" << endl;
    else if (s == "Polonia") cout << "kura" << endl;
    else if (s == "Argentina") cout << "gallina" << endl;
    else if (s == "Brasil") cout << "galinha" << endl;
    else if (s == "Finlandia") cout << "kana" << endl;
    else if (s == "Italia") cout << "gallina" << endl;
    else if (s == "Egito") cout << "farkha" << endl;
    else if (s == "Franca") cout << "poule" << endl;
    else if (s == "Israel") cout << "tarnegolet" << endl;
}