//Fatoração Prima

vector<int> factor(int n) {
    vector<int> primes;
    for (int p = 2; p * p <= n; ++p) {
        while (n % p == 0) {
            primes.push_back(p);
            n /= p;
        }
    }
    if (n > 1) 
        primes.push_back(n);
    return primes;
}


