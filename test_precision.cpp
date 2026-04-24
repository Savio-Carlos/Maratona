#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long maior = 100000000000000000LL - 1;
    cout << "sqrt: " << (long long)sqrt(maior) << endl;
    cout << "sqrtl: " << (long long)sqrtl(maior) << endl;
    return 0;
}
