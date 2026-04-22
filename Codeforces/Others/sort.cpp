#include <iostream>
#include <string>
#include <vector>
using namespace std;

int verifica (string s, string s2, int n, int l, int r, vector<bool> is_visited){
    int ans = 0;
    //cout << s << "   " << s2 << " "<< n << l << r << endl;
    for (int i = l; i < r; i++){
        for (int j = l; j < r; j++){
            if (s[i] == s2[j] && !is_visited[j]) {
                ans++;
                is_visited[j] = true;
                break;
            }
            //cout << s2[i] << " visitado ou nao " << is_visited[j] << endl;
        }
    }
    return (r-l) - ans;
}



int main () {
    int t, n, q, l, r;
    string s1, s2;
    cin >> t;
    while(t--){
        cin >> n >> q;
        cin >> s1 >> s2;
        while (q--){
            cin >> l >> r;
            vector<bool> is_visited(n);
            cout << verifica(s1, s2, n, l-1, r, is_visited) << endl;
        }
    }
}