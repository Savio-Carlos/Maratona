#include <iostream>
using namespace std;

int main(){
    double c,d,t;
    cin >> c >> d >> t;
    double res = (d - (c*t))/c;
    if (res < 0) res = 0;

    printf ("%.1lf", res);

    return 0;
}