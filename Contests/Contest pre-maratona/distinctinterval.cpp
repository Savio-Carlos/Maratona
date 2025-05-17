#include <iostream>
using namespace std;

int main() {
    int n, contador = 0, aux2 = 0, c, res = 0;
    cin >> n;
    bool arr[100001];
    int aux[100001];

    for (int i = 0; i < n; i++){
        cin >> c;
        contador++;

        if (arr[c]) {
            arr[c] = false;
            aux2 = i - aux[c];
            contador = 1;

        }

        arr[c] = true;

        aux[c] = i;

        res = max(contador, res);

        cout << "contador = " << contador << " || ";
        cout << "res = " << res << " || ";
        cout << "aux 2 = " << aux2 << endl;
        aux2 = 0;
    }

    cout << res << endl;
}