//Number of Pairs (GCD e LCM)
/*
alguma coisa de manipular a expressao ja que o lcm(a,b) = a*b/gcd(a,b)
x = c*(a*b/gcd(a,b)) - d*gcd(a,b)
gcd(a,b) = g
 
lcm(a,b) = g*x*y onde gcd(x,y) = 1
 
por ex se x = 5 e y = 3
lcm(5,3) = 5*3*gcd(5,3){1} = 15
se a,b nao forem coprimos achamos um x,y que fazem eles serem coprimos, de maneira que
 
a = 4
b = 6
 
lcm(a,b) = 12
gcd(a,b) = 2
 
lcm(a,b) = x*y*gcd(a,b)
12 = x*y*2
x*y = 6
x = 3
y = 2
ou 
x = 6
y = 1
 
lcm(4,6) = 3*2*2 correto
lcm(4,6) = 6*1*2 correto
 
entao lcm(a,b) = x*y*gcd(a,b)
 
x = c*x*y*g - d*g
x = g((c*x*y) - d)
x/g = c*x*y - d
*/
 
 
int spf[MAX], factors[MAX];
 
void build(){
    spf[1] = 1;
    for (int i = 2; i < MAX; i+=2) spf[i] = 2;
    for (int i = 3; i < MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i < MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}
 
void buildfactors(){
    for (int i = 2; i < MAX; i++){
        factors[i] = factors[i/spf[i]];
        if (spf[i/spf[i]] != spf[i]) factors[i]++;
    } 
}
 
vector<int> getdiv(int x){
    vector<int> d;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0){ 
            d.push_back(i);
            if (i*i!=x) d.push_back(x/i);
        }
    }
    sort(all(d));
    return d;
}
 
void solve(){
    int c, d, x;
    cin >> c >> d >> x;
    vector<int> divisors = getdiv(x);
    int ans = 0;
    for (auto gc : divisors){
        if (((x/gc)+d) % c != 0) continue;
        int goal = (x/gc + d) / c;
        //goal significa que eu quero achar dois caras que multiplicados sejam goal, e o gcd deles seja 1
        //nisso eu vou descobrir a2 e b2, para achar a e b eu multiplico pelo u (gcd(a,b)) e calculo o lcm e depois testo os pares n sei como ainda
        //aqui eu acho o lcm e consigo descobrir o gcd de a e b
        // no caso o gcd ja eh meu divisor
        // ai basta achar as combinacoes validas de a e b
        // fatorar o goal e ver os fatores primos, para cada fator primo, a e b podem optar por receber ou nao ele
        // todos os fatores primos precisam ser usados, ou em a ou em b
        // entao temos como resposta a adicao de todas as combinacoes de k (qtd de fatores primos) em a,b
        int k = factors[goal];
        //debug(k);
        ans += (1<<k);   
    }
    cout << ans << endl;
}
 
signed main(){
    winton;
    build();
    buildfactors();
    int t;
    cin >> t;
    while(t--)solve();
}