#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define ll long long
const int INF = 1e9+7;


signed main () {_
    double a, b, c;
    cin >> a >> b >> c;
    double p = a/b;
    double d = c/p;
    double ak = a*b;
    double ac = d*c;
    printf("%.2lf %.2lf %.2lf\n", d, ak, ac);
}