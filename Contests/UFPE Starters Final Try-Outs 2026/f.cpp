#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    cerr << line << ": ";
    while (!s.empty() && s[0] == ' ') s = s.substr(1);
    int pos = 0;
    int bracket = 0;
    while (pos < (int)s.size() && (s[pos] != ',' || bracket > 0)) {
        if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{') bracket++;
        if (s[pos] == ')' || s[pos] == ']' || s[pos] == '}') bracket--;
        pos++;
    }
    cerr << s.substr(0, pos) << " = " << h;
    if (sizeof...(t)) cerr << " | ";
    debug_out(pos < (int)s.size() ? s.substr(pos + 1) : "", line, t...);
}

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

const int MOD = 1e9+7;

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}

int modinv(int n) {
    return fastExpo(n, MOD - 2);
}

int modiv(int a, int b) {
    return (a * modinv(b)) % MOD;
}

void solve(){
    int n;
    cin >> n;
    int l = n&1 ? 1 : 2;
    int r = (n-1) / 2;

    if (l > r){
        cout << 0 << endl;
        return;
    }

    int tot = modiv(((n-1) * (n-2)) % MOD, 2);
    
    if (l == 2) r--;
    int ways = modiv((r * (r+1)) % MOD, 2);
    debug(ways, tot);
    cout << modiv(ways,tot) << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}

/*
pra ter um triagulo preciso que a soma dos dois lados menores seja > que o 3 lado
para o primeiro ponto posso escolher no maximo a metade
precisamente (n-1)/2 vai ser o maior ponto que posso escolher
dado esses pontos, preciso escolher o outro de maneira que esse primeiro segmento seja o maior

numero total de combinacoes de pontos seria ((N - 1)*(N - 2))/2 
pois n posso escolher o ponto 0 nem o N, entao tenho N-1 pontos validos

se eu tentar garantir que o primeiro segmento vai ser o maior, o valor maximo seria N-1 / 2
mas qual o valor minimo? N/3 -> desse jeito todos vao ter o mesmo tamanho
N/3 + 1 isso n garante que vai ser o maior, pra ser o maior seria n-1/2 mesmo
o minimo e 1 se impar 2 se par



e depois eu acho de quantas maneiras posso fazer essa combinacao de tamanho



*/