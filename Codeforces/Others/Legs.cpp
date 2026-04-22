#include <iostream>
using namespace std;

int main () {
    int t, n;
    cin >> t;
    while (t--){
        int contador = 0;
        cin >> n;
        while (n){
            if (n >= 4){
                n-=4;
                contador++;
            }
            else if (n >= 2){
                n-=2;
                 contador++;
            }
            else break;

        }
        cout << contador << endl;
    }

    return 0;
}