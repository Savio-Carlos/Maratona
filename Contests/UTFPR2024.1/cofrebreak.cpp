#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0, biggest = 0, meiostart = -1;

    while (i < n) {
        unordered_set<ll> visitado;
        int final = i;

        while (final < n && visitado.find(arr[final]) == visitado.end()) {
            visitado.insert(arr[final]);
            final++;
        }

        if (final - i > biggest) {
            biggest = final - i;
            meiostart = i;
        }
        i++;
    }

    if (meiostart != -1) {
        reverse(arr.begin() + meiostart, arr.begin() + meiostart + biggest);
    }

    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }

    cout << endl;
    return 0;
}