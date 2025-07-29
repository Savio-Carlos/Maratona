#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 1e6+7;
const int MOD = 1e9+7;

/*
alguma coisa de manipular a expressao ja que o lcm(a,b) = a*b/gcd(a,b)
x = c*(a*b/gcd(a,b)) - d*gcd(a,b)
gcd(a,b) = g

lcm(a,b) = g*x*y onde gcd(x,y) = 1

por ex se x = 5 e y = 3
lcm(5,3) = 5*3*gcd(5,3){1} = 15
se a,b nao forem coprimos achamos um x,y que fazem eles serem coprimos, de maneira que

a = 4
b = 6

lcm(a,b) = 12
gcd(a,b) = 2

lcm(a,b) = x*y*gcd(a,b)
12 = x*y*2
x*y = 6
x = 3
y = 2
ou 
x = 6
y = 1

lcm(4,6) = 3*2*2 correto
lcm(4,6) = 6*1*2 correto

entao lcm(a,b) = x*y*gcd(a,b)

x = c*x*y*g - d*g
x = g((c*x*y) - d)

*/
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int mmc(int a, int b) {
    return a / gcd(a, b) * b;
}

signed main(){
    winton;
    int c, d, x;
    cin >> c >> d >> x;


}