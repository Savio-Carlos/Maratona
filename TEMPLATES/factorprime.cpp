#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> arr;

void factor (ll n){
    for (int i = 2; i < sqrt(n); i++){
        while (n%i == 0){
        n = n/i;
        arr.push_back(i);//arr.push_back(i); aqui ele adiciona o mesmo numero mais de uma vez, fatoracao normal
        cout << n << endl;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    factor(n);
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " "; 
    }
}