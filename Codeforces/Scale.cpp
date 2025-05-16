#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> arr;
vector<int> arr2;

int main (){
    int t, n, k, red;
    cin >> t;
    string s;
    while (t--){
        cin >> n >> k;
        red = n/k;
        arr.resize(n*n);
        arr2.resize(red*red);

        for (int i = 0; i < n; i++){
            cin >> s;
            for (int j = 0; j < n; j++){
                arr[i*n+j] = s[j] - '0';
                //cout << " posicao " << i*n+j << " = "<< arr[i*n+j];
            }
            //cout << endl;
        }

        //cout << red << endl;
        int minicount = 0, aux = 0;
        for (int i = 0; i < red*red ; i++){
            if (minicount == red && red!=n) {
                aux +=n*(k-1);
                minicount = 0;
            }
            minicount++;
            arr2[i] = arr[i*k +aux];
            //cout << i << " k= " << k << "aux = "<< aux << endl;
            //cout<< i*k +aux << " ";
        }
    
        for (int i = 0; i < red; i++){
            for (int j = 0; j < red; j++){
                cout << arr2[i*red+j];
                //cout << " " <<i*red+j << " ";
            }
            cout << endl;
        }

    }

    return 0;

}