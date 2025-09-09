int power(int base, int exp) {
    int res = 1;
    base %= MOD; 
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}