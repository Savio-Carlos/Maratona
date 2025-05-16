#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, int p1, int p3, int p2)
{
    if (n == 0) {
        return;
    }
    //cout << n << "    " << p1 << " " << p2 << " " << p3 << endl;;
    towerOfHanoi(n - 1, p1, p2, p3);
    cout << p1 << " " << p3 << endl;
    towerOfHanoi(n - 1, p2, p3, p1);
}

int main()
{
    int N, n = 0;
    cin >> N;
    for (int i = 0; i < N; i++){
        n = n*2 + 1;
    }
    cout << n << endl;
    towerOfHanoi(N, 1, 3, 2);
    return 0;
}

