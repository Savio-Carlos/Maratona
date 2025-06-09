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

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int cnt1 = 0, cnt0 = 0;
        int p1 = 0, p0 = 0;
        string s;
        int k, n;
        cin >> n >> k;
        cin >> s;
        //cout << s << endl;
        for(int i = 0; i < n; i++){
            if (s[i] == '1'){
                cnt1++;
                if (s[n-i-1] == '1') p1++;
            }
            if (s[i] == '0'){
                cnt0++;
                if (s[n-i-1] == '0') p0++;
            }
        }
        p1/=2;
        p0/=2;
        //cout << cnt1 << " " << cnt0 << endl;
        if (p1+p0 == k) cout << "YES" << endl;
        else if ((cnt0 == 0 || cnt1==0) && k < (cnt1/2 + cnt0/2)) cout << "NO" << endl;
        else if ((cnt1/2 + cnt0/2)%2 == k%2 && (cnt1/2 + cnt0/2)>=k && k >= ((max(cnt1,cnt0)/2) - min(cnt1,cnt0)/2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
/*
10 2
11010 11001
10011

o numero de palindromes ta relacionado com o numero de 0 e 1
se o numero de 0/1 for par eu consigo formar m/2 palindromes daquele
vamos supor que eu tenho 5 1 e 5 0 e quero formar 2 palindromes
eu consigo fazer isso mas ai fica 3 e 3, como ambos sao impares entao eu sempre formo um palindrome 
se ambos sao impares eu so consigo formar um numero k impar de palindromes (lembrar de respeitar a restricao do k)
se ambos forem pares eu consigo formar m/2 palindromes
por ex 4 2, consigo formar 3 palindromes, ou 1 palindrome
mas se fosse 4 4 eu consigo formar ou 2 ou 4 palindromes

5 e 3 seriam 1 ou 3 palindromes
4 e 6 seriam 5 ou 3 palindromes
11000
10100
7 3  podem ser 2 ou 4 palindromes
1111
0111
9 e 3 seriam impares palindromes
9 e 5 seriam pares palindromes
7 e 1 seriam impares palindromes

como determinar se o numero de palindromes e par ou impar?
1
10 1
11110
11101
nesse caso eu posso fazer 5 e 3 palindromes mas nao 1
entao eu preciso checar se a quantidade max de palindromes q eu posso nao fazer e menor que K
nesse caso essa quantia e 2 pois e a quantidade do menor entre cnt1 e cnt 0
*/