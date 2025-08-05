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

int fastExpo(int base, int exp) {
    int r = 1;
    base %= MOD;
    while(exp) {
        if (exp & 1) r = r * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return r;
}

int modinverse(int n) {
    return fastExpo(n, MOD - 2);
}

int modiv(int a, int b){
    return (a * modinverse(b))%MOD;
}

signed main(){
    winton;
    int n;
    cin >> n;
    bool finalimpar = true;
    vector<int> p(n), k(n);
    int cnt = 1, sum = 1, prod = 1, cnt2 = 1;
    for (int i = 0; i < n; i++){
        cin >> p[i] >> k[i];
        if (k[i]&1) finalimpar = false;
    }
    for (int i = 0; i < n; i++){          
        cnt = (cnt * (k[i]+1)) % MOD;
        cnt2 = (cnt2 * (k[i]+1)) % (2*(MOD-1));
        /*
        se a gente so fizer %MOD-1 corremos o risco de perder a paridade do valor
        se a gente perder a paridade isso da problema mais na frente quando formos dividir cnt2/2
        aqui K = MOD-1
        fazer 2(MOD-1) da certo pq N e N % 2K diferem apenas por um multiplo de 2K
        e como N = q⋅(2K)+r
        como r = resto e q*(2K) vai ser par
        o resto e a mesma coisa que N % 2K
        entao o resto se mantem igual

        N%2 = r%2
        isso pq o (q*2K)%2 sempre vai dar 0
        Conclusão: Como r=N(mod2K), a equação final nos diz que: N(mod2)=(N(mod2K))(mod2) 
        
        */
        
        int exp = (k[i] % (MOD-1));
        exp = (exp+1) % (MOD-1);
        //debug(exp);
        int num = (fastExpo(p[i],exp)-1 + MOD) % MOD;
        int den = (p[i]-1 + MOD) % MOD;
        sum = (sum * modiv(num,den)%MOD)%MOD;
    }
    // debug(cnt);
    // debug(cnt2);
    for (int i = 0; i < n; i++){       
        if (!finalimpar){
            /*
            se chegamos aqui algum expoente e impar e o cnt2 e par, entao precisamos dividir o cnt/2
            como ele e um expoente precisamos dele no MOD-1,
            mas como n podemos dividir isso por 2 por n exisitr inverso modular a gente mantem 2*MOD
            2*MOD mantem a paridade do numero original enquanto o MOD-1 pode nao manter
            isso traria problemas pra gente
            */
            int half = (cnt2/2)%(MOD-1);
            int exp = (k[i]*half)%(MOD-1);
            prod = (prod * (fastExpo(p[i],exp)%MOD)) % MOD;
        }
        else{
            /*
            se o numero total de divisores e impar (cnt2)
            cada expoente k[i] tem paridade par
            isso por que pra acontecer de ser impar no final, nos so multiplicamos produtos impares
            como a gente multiplica k+1, entao todo ki tem que ser par originalmente
            com isso a gente pode dividir cada ki/2 e isso sempre vai ser um inteiro
            ai e so escrever k[i]/2*cnt2 que vai dar certo
            */
            int exp = ((k[i]/2)*cnt2)%(MOD-1);
            prod = (prod * (fastExpo(p[i],exp)%MOD)) % MOD;
        }
    }
    cout << cnt%MOD << ' ' << sum%MOD << ' ' << prod%MOD << endl;
}