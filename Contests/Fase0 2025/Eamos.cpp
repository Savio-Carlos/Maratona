#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define int long long
#define endl "\n"

vector<int> arr;

std::vector<int> factorize(int n) {
    while (n % 2 == 0) {
        arr.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        while (n % i == 0) {
            arr.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        arr.push_back(n);
    }
    return arr;
}

// void factor (int n){
//     int max = n;
//     for (int i = 2; i <= max; i++){
//         while (n%i == 0){
//             n /= i;
//             arr.push_back(i);//arr.push_back(i); aqui ele adiciona o mesmo numero mais de uma vez, fatoracao normal
//             // cout << n << endl;
//         }
//     }
// }

signed main(){
    fastio;
    int y, k;
    cin >> y >> k;

    // Insere 1
    arr.push_back(1);
    factorize(y); // Fatora y
    // arr.push_back(y); // Insere y

    //debug
    // for(auto a:arr) cout << a << " ";
    // cout << endl;


    bool antes = false;

    int maior_divisor = 1, ans = 0, i = 0, acc = 1;
    for(;i < arr.size() - 1; i++){
        acc *= arr[i];
        int prox =  acc * arr[i+1];
        
        if (ans + (acc * arr[i+1] - acc)/acc > k) {
            antes = true;
            break;
        }
        ans += (acc * arr[i+1] - acc)/acc;
        // cout << ans << endl;
        // cout <<"acc " << acc << endl;
        // cout << acc << " " << prox << " " <<ans<<endl;
    }

    // cout << ans << " " << acc << endl;

    if (antes){
        // cout << "antes" << endl;
        cout << acc + (k - ans) * acc << endl; 
    } else cout << y + (k - ans) * y << endl;

   

    // cout << acc * (k - ans) << endl;

    // ans e a quantidade


    return 0;
}