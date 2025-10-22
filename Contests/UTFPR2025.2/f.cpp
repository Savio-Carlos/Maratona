#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, F;
    if (!(cin >> N >> F)) return 0;
    const int M = 1 << F;
    vector<long long> freq(M, 0);
    
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        int mask = 0;
        for (int j = 0; j < F; ++j) {
            if (s[j] == 'S') mask |= (1 << j);
        }
        ++freq[mask];
    }
    
    int FULL = M - 1;
    long long ans = 0;
    for (int a = 0; a < M; ++a) {
        if (!freq[a]) continue;
        for (int b = a; b < M; ++b) {
            if (!freq[b]) continue;
            if ((a | b) == FULL) {
                if (a == b) ans += freq[a] * (freq[a] - 1) / 2;
                else ans += freq[a] * freq[b];
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
