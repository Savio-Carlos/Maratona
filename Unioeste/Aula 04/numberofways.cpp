#include <iostream>
using namespace std;

long long int d[1000];

int countWays(int S, int E) {
    if (S == E)
        return 1;
    if (S > E)
        return 0;
    if (d[S] != -1) return d[S];    

    return d[S] = countWays(S + 1, E) + countWays(S + 2, E) + countWays(S + 3, E);
}

int main() {
    int S, E;
    cin >> S >> E;

    for (int i = 0; i < 1000; i++){
        d[i] = -1;
    }

    long long int n = countWays(S, E);
    cout << n << endl;

    return 0;
}
