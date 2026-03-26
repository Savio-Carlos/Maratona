#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void tprimo (int i){
    
    int square = sqrt(i);
    
    int erros = 0;
    
    if (i <= 3){
        erros++;
    }
    if (square%2 == 0 && i != 4){
        erros++;
    }
    if (square%3 == 0 && i != 9){
        erros++;
    }
    if (square%5 == 0 && i != 25){
        erros++;
    }
    if (i%2 == 0 && i != 4){
        erros++;
    }
    if (i%3 == 0 && i != 9){
        erros++;
    }
    if (i%5 == 0 && i != 25){
        erros++;
    }
    
    if (erros > 0){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }

}

int main(){
    
    int n; cin >> n;
    
    vector<int> nums;
    
    for (int i = 0; i < n; i++){
        
        int a; cin >> a;
        
        nums.push_back(a);
    
    }
    
    for (auto i : nums){
        
        tprimo(i);
        
    }
    
    return 0;
}