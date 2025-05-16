#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int sapato[30][2], i = n, x, cnt = 0;
    char c;

    while(i--){
        cin >> x >> c;
        if (c == 'E') sapato[x-30][0]++;
        else if (c == 'D') sapato[x-30][1]++;
    }
    for (i = 0; i < 30; i++) {
        cnt += std::min(sapato[i][0], sapato[i][1]);
    }
    cout << "\n" << cnt << endl;

}