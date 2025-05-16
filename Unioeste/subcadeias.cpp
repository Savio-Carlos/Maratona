#include <iostream>
#include <string.h>
using namespace std;

bool palindrome(string str, int i, int j){
        while(i<j){
            if (str[i] != str[j]) {
            return false;
            }
            i++;
            j--;
        }
    return true;
}

int main() {
    int n , maior=1; cin >> n;
    string str;
    cin >> str;

    for (int i = 0; i < n; i++){
        char c = str[i];
        for (int j = i; j < n; j++){
            if (palindrome(str, i, j)) {
            maior = max(maior, j-i+1);
            
            }
        }
    }
    
    cout << maior << endl;

    return 0;
}