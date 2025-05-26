#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

int n;  
int size;

string palindrome(string s, int len) {
    string p(len, '0');
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
        p[i] = s[i];
    }
    for (int i = 0; i < len / 2; i++) {
        p[len - 1 - i] = p[i];
    }
    return p;
}

string bi(int n) {
    if (n == 0) {
        return "0";
    }
    string b;
    while (n > 0) {
        b += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    reverse(b.begin(), b.end());
    return b;
}

int numero(string s){
    int res = 0;
    for (char u : s) {
        res <<= 1; 
        if (u == '1') {
            res |= 1;
        }
    }
    return res;
} 

signed main(){
    winton;
    cin >> n;

    string s = bi(n);
    int meio = (s.size() + 1) / 2;
    string pfx = s.substr(0, meio);
    string pos = palindrome(pfx,s.size());
    //cout << pos << endl;
    //cout << pfx << endl;
    if (pos <= s) {
        cout << numero(pos) << endl;
        return 0;
    }
    int menor = numero(pfx);
    menor--;
    int l = 1ULL << (meio - 1);

    if (menor < l) {
        int ans = ( (s.size)() - 1) == 0 ? 0ULL : ((1ULL << (s.size)() - 1)) - 1ULL;
        cout << ans << endl;
        return 0;
    }
    string pfx2(meio, '0');
    int temp = menor;
    for (int i = meio - 1; i >= 0; i--) {
        pfx2[i] = char('0' + (temp & 1));
        temp >>= 1;
    }

    string res2 = palindrome(pfx2,s.size());
    cout << numero(res2) << endl;

}

