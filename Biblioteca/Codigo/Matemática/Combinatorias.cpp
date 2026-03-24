//Combinatoria

const int MOD = 1e9+7;

const int MOD = 998244353;
const int MAX = 1e6+7;

int fat[MAX], invfat[MAX];

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

void build(){
    fat[0] = 1;
    for (int i = 1; i < MAX; i++) fat[i] = (fat[i-1] * i) % MOD;
    invfat[MAX-1] = modinv(fat[MAX-1]);
    for (int i = MAX - 2; i >= 0; i--) invfat[i] = (invfat[i+1] * (i+1)) % MOD;
}
int comb(int a, int b){
    if (a > b || a < 0 || b < 0) return 0;
    return (((fat[b] * invfat[a]) % MOD) * invfat[b-a]) % MOD;
}

int combinations(int n, int k) {
    // Basic edge cases
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n - k) {
        k = n - k;
    }
    int res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int combinations_mod(int n, int k) {
    if (k < 0 || k > n)  return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    int numerator = 1;
    for(int i = 0; i < k; i++) numerator = (numerator * (n - i)) % MOD;
    int denominator = 1;
    for(int i = 1; i <= k; i++) denominator = (denominator * i) % MOD;
    return (numerator * modinv(denominator)) % MOD;
}
